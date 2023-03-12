#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define MAXCOUNT 5

#define READER1  50000
#define READER2 100000
#define READER3	400000
#define READER4 800000
#define WRITER1  150000

typedef struct {
	pthread_mutex_t *mut;
	int writers;
	int readers;
	int waiting;
	pthread_cond_t *writeOK, *readOK;
} rwl;// readear writer lock works as semaphore to avoid race condition

rwl *initlock (void);//initialize lock
void readlock (rwl *lock, int d);
void writelock (rwl *lock, int d);
void readunlock (rwl *lock);
void writeunlock (rwl *lock);
void deletelock (rwl *lock);

typedef struct {
	rwl *lock;
	int id;
	long delay;
} rwargs;// read write arguments

rwargs *newRWargs (rwl *l, int i, long d);
void *reader (void *args);
void *writer (void *args);

static int data = 1;

int main ()
{
	pthread_t r1, r2, r3, r4, w1;
	rwargs *a1, *a2, *a3, *a4, *a5;
	rwl *lock;

	lock = initlock ();// initialize lock
	a1 = newRWargs (lock, 1, WRITER1);//creating arguments for thread function
	pthread_create (&w1, NULL, writer, a1);//create thread
	a2 = newRWargs (lock, 1, READER1);
	pthread_create (&r1, NULL, reader, a2);//create_thread arguments(identifier/name, attributes, thread function,function arguments)
	a3 = newRWargs (lock, 2, READER2);
	pthread_create (&r2, NULL, reader, a3);
	a4 = newRWargs (lock, 3, READER3);
	pthread_create (&r3, NULL, reader, a4);
	a5 = newRWargs (lock, 4, READER4);
	pthread_create (&r4, NULL, reader, a5);
	pthread_join (w1, NULL);//joining thread so that progra dos not terminate when thread terminates ie waits for program
	pthread_join (r1, NULL);
	pthread_join (r2, NULL);
	pthread_join (r3, NULL);
	pthread_join (r4, NULL);
	free (a1); free (a2); free (a3); free (a4); free (a5);//free mem

	return 0;
}

rwargs *newRWargs (rwl *l, int i, long d)//returns structure of arguments for creating thread
{
	rwargs *args;

	args = (rwargs *)malloc (sizeof (rwargs));
	if (args == NULL) return (NULL);
	args->lock = l; args->id = i; args->delay = d;
	return (args);
}

void *reader (void *args)
{
	rwargs *a;
	int d;

	a = (rwargs *)args;

	do {
		readlock (a->lock, a->id);//reader cs entry code
		d = data;
		usleep (a->delay);// time to read so thread is put to sleep
		readunlock (a->lock);//reader cs exit code
		printf ("Reader %d : Data = %d\n", a->id, d);
		usleep (a->delay);//to avoid starvation of other threads
	} while (d != 0);//condition for readers to finish
	printf ("Reader %d: Finished.\n", a->id);

	return (NULL);
}

void *writer (void *args)
{
	rwargs *a;
	int i;

	a = (rwargs *)args;

	for (i = 2; i < MAXCOUNT; i++) {
		writelock (a->lock, a->id);//writer cs entry code
		data = i;//writer change shared variable value
		usleep (a->delay);//put writer to sleep
		writeunlock (a->lock);//writer cs exi code
		printf ("Writer %d: Wrote %d\n", a->id, i);
		usleep (a->delay);//put writer to sleep to avoid starvation
	}
	printf ("Writer %d: Finishing...\n", a->id);
	writelock (a->lock, a->id);
	//while exiting the writer chages data to 0
	//changing value of common data to 0 for readers to finish reading
	data = 0;
	writeunlock (a->lock);
	printf ("Writer %d: Finished.\n", a->id);

	return (NULL);
}

rwl *initlock (void)//initialize lock
{
	//allocate memory to all declared pointers
	rwl *lock;

	lock = (rwl *)malloc (sizeof (rwl));
	if (lock == NULL) return (NULL);
	lock->mut = (pthread_mutex_t *) malloc (sizeof (pthread_mutex_t));
	if (lock->mut == NULL) { free (lock); return (NULL); }
	lock->writeOK =
		(pthread_cond_t *) malloc (sizeof (pthread_cond_t));
	if (lock->writeOK == NULL) { free (lock->mut); free (lock);
		return (NULL); }
	lock->readOK =
		(pthread_cond_t *) malloc (sizeof (pthread_cond_t));
	if (lock->writeOK == NULL) { free (lock->mut); free (lock->writeOK);
		free (lock); return (NULL); }

	pthread_mutex_init (lock->mut, NULL);//lock->mut initialization
	pthread_cond_init (lock->writeOK, NULL);//lock->writeOK initilization
	pthread_cond_init (lock->readOK, NULL);//lock-> readOK initilization
	lock->readers = 0;//initially all are 0
	lock->writers = 0;
	lock->waiting = 0;

	return (lock);
}

void readlock (rwl *lock, int d)
{
	//Block the reader if any writer is making a change to shared variable till the writer is having access to shared variable
	pthread_mutex_lock (lock->mut);//does not allow other process, threads t access lock->mut
	if (lock->writers || lock->waiting) {//lock->writer: number of writers in critical section
		do {                             //lock->waiting: number of threads waiting for critical section
			printf ("reader %d blocked.\n", d);
			pthread_cond_wait (lock->readOK, lock->mut);
			printf ("reader %d unblocked.\n", d);
		} while (lock->writers);         //lock->writer: number of writers in critical section
	}
	// else increment the readers holding the lock variable
	lock->readers++;
	pthread_mutex_unlock (lock->mut);

	return;
}

void writelock (rwl *lock, int d)
{
	pthread_mutex_lock (lock->mut);//mut locked
	lock->waiting++;
	//if any reader or writer is accessing a shared variable then this writer cannot enter the critical section
	while (lock->readers || lock->writers) {
		printf ("writer %d blocked.\n", d);
		pthread_cond_wait (lock->writeOK, lock->mut);//unlocks mutex and waits for signal
        //equivalent to
        // pthread_mutex_unlock(lock->mut)
        //wait for signal on lock->writeOK
        //pthread_mutex_lock(lock->mut)
		printf ("writer %d unblocked.\n", d);
	}
	//else allow the writer inside critical section
	lock->waiting--;// since writer is not waiting
	lock->writers++;
	pthread_mutex_unlock (lock->mut);

	return;
}

void readunlock (rwl *lock)
{
	pthread_mutex_lock (lock->mut);
	lock->readers--;
	if (lock->readers == 0) //***********************************
pthread_cond_signal (lock->writeOK);//if no readers are reading signal the writer to perform its task(use cond broadcast for multiple writers)
	pthread_mutex_unlock (lock->mut);//mut unlocked for other threads
}

void writeunlock (rwl *lock)
{
	pthread_mutex_lock (lock->mut);
	//decrement the writer variable indicating writer of that particular thread has finished writing
	lock->writers--;
	if (lock->writers == 0)
	pthread_cond_broadcast (lock->readOK);//signalling all readers to read the data as writer has finished
	pthread_mutex_unlock (lock->mut);
}

void deletelock (rwl *lock)
{
	pthread_mutex_destroy (lock->mut);
	pthread_cond_destroy (lock->readOK);
	pthread_cond_destroy (lock->writeOK);
	free (lock);

	return;
}

