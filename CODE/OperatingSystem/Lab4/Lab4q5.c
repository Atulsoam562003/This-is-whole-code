#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define MAXCOUNT 5
#define SIMREAD 3

#define READER1 50000
#define READER2 100000
#define READER3 400000
#define READER4 800000
#define READER5 200000
#define READER6 50000
#define READER7 100000
#define READER8 400000
#define READER9 800000
#define READER10 200000
#define WRITER1 150000
#define WRITER2 500000
#define WRITER3 200000
#define WRITER4 300000
#define WRITER5 250000

// structure named rwl
typedef struct
{
    pthread_mutex_t *mut;
    // pthread_mutex_t is a data type to manage locks and unlocks on threads
    int writers;
    int readers;
    int waiting;
    pthread_cond_t *writeOK, *readOK;
    // pthread_cond_t is a POSIX condition variable used for inter-thread communication
    // Here writeOK and readOK are two variables of the above type that signal another threads
    // if they can read or write now
} rwl;
// reader writer lock acts as a seamophere to avoid race condition

rwl *initlock(void); // initialise a lock
void readlock(rwl *lock, int d);
void writelock(rwl *lock, int d);
void readunlock(rwl *lock);
void writeunlock(rwl *lock);
void deletelock(rwl *lock);

typedef struct
{
    rwl *lock;
    int id;
    long delay;
} rwargs;

rwargs *newRWargs(rwl *l, int i, long d);
void *reader(void *args);
void *writer(void *args);

static int data = 1;

int main()
{
    pthread_t r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, w1, w2, w3, w4, w5;
    // declaring r1,r2,r3,r4,rs as our POSIX threads
    rwargs *a1, *a2, *a3, *a4, *a5, *a6, *a7, *a8, *a9, *a10, *a11, *a12, *a13, *a14, *a15;
    rwl *lock;

    lock = initlock();

    // initilises a1 definng its id and the required time
    // Creation of threads :
    // first arguments is thread id or thread identifier
    // second argumet is thread attributes (NULL in this case)
    // third argument is function which the thread operates upon (writer goes in writer function and similar for writer)
    // fourth argument is argument of the thread function (variable of structure rwargs in our case)
    a1 = newRWargs(lock, 1, WRITER1);
    pthread_create(&w1, NULL, writer, a1);
    a2 = newRWargs(lock, 1, READER1);
    pthread_create(&r1, NULL, reader, a2);
    a3 = newRWargs(lock, 2, READER2);
    pthread_create(&r2, NULL, reader, a3);
    a4 = newRWargs(lock, 3, READER3);
    pthread_create(&r3, NULL, reader, a4);
    a5 = newRWargs(lock, 4, READER4);
    pthread_create(&r4, NULL, reader, a5);
    a6 = newRWargs(lock, 2, WRITER2);
    pthread_create(&w2, NULL, writer, a6);
    a7 = newRWargs(lock, 3, WRITER3);
    pthread_create(&w3, NULL, writer, a7);
    a8 = newRWargs(lock, 4, WRITER4);
    pthread_create(&w4, NULL, writer, a8);
    a9 = newRWargs(lock, 5, WRITER5);
    pthread_create(&w5, NULL, writer, a9);
    a10 = newRWargs(lock, 5, READER5);
    pthread_create(&r5, NULL, reader, a10);
    a11 = newRWargs(lock, 6, READER6);
    pthread_create(&r6, NULL, reader, a11);
    a12 = newRWargs(lock, 7, READER7);
    pthread_create(&r7, NULL, reader, a12);
    a13 = newRWargs(lock, 8, READER8);
    pthread_create(&r8, NULL, reader, a13);
    a14 = newRWargs(lock, 9, READER9);
    pthread_create(&r9, NULL, reader, a14);
    a15 = newRWargs(lock, 10, READER10);
    pthread_create(&r10, NULL, reader, a15);
    
    pthread_join(w1, NULL);
    pthread_join(r1, NULL);
    pthread_join(r2, NULL);
    pthread_join(r3, NULL);
    pthread_join(r4, NULL);
    pthread_join(w2, NULL);
    pthread_join(r5, NULL);
    pthread_join(r6, NULL);
    pthread_join(r7, NULL);
    pthread_join(r8, NULL);
    pthread_join(w3, NULL);
    pthread_join(w4, NULL);
    pthread_join(w5, NULL);
    pthread_join(r9, NULL);
    pthread_join(r10, NULL);
    // main function waits for all the created threads to finish their task using pthread_join()
    free(a1);
    free(a2);
    free(a3);
    free(a4);
    free(a5);
    free(a6);
    free(a7);
    free(a8);
    free(a9);
    free(a10);
    free(a11);
    free(a12);
    free(a13);
    free(a14);
    free(a15);

    return 0;
}

rwargs *newRWargs(rwl *l, int i, long d)
{
    rwargs *args;

    args = (rwargs *)malloc(sizeof(rwargs));
    if (args == NULL)
        return (NULL);
    args->lock = l;
    args->id = i;
    args->delay = d;
    return (args);
}

void *reader(void *args)
{
    rwargs *a;
    int d;

    a = (rwargs *)args;
    if(a->lock->readers>=SIMREAD && a->lock->waiting) 
    {
        usleep(2);
        
//printf("hii\n");
    }
   
    
        do
    {
        readlock(a->lock, a->id);
        d = data;
        usleep(a->delay); // takes delay amount of time to read and hence the thread is put to sleep
        // using the usleep() call
        readunlock(a->lock);
        // we check now the data that reader has read
        printf("Reader %d : Data = %d\n", a->id, d);
        // put the thread to sleep to avoid starvation of other threads
        usleep(a->delay);
    } while (d != 0) ;
    printf("Reader %d: Finished.\n", a->id);
    

    return (NULL);
}

void *writer(void *args)
{
    rwargs *a;
    int i;

    a = (rwargs *)args;

    for (i = 2; i < MAXCOUNT; i++)
    {
        writelock(a->lock, a->id);
        data = i;             // here,writer has changed the shared variable's value
        usleep(a->delay);     // now,put the current thread to sleep
        writeunlock(a->lock); // unlock the mutex
        printf("Writer %d: Wrote %d\n", a->id, i);
        usleep(a->delay);
        // After we have printed what writer has changed put writer thread to sleep to avoid starvation
    }

    printf("Writer %d: Finishing...\n", a->id);
    writelock(a->lock, a->id);
    // Manually changing the value of shared variable to 0
    // in order for reader threads to terminate(as we have put the condition in void* reader(void *args) function above)
    data = 0;
    writeunlock(a->lock);
    // unlock the writer thread
    printf("Writer %d: Finished.\n", a->id);

    return (NULL);
}

rwl *initlock(void)
{
    rwl *lock;

    // Allocate memeory to all the declared pointers
    lock = (rwl *)malloc(sizeof(rwl));
    if (lock == NULL)
        return (NULL);
    lock->mut = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
    if (lock->mut == NULL)
    {
        free(lock);
        return (NULL);
    }
    lock->writeOK =
        (pthread_cond_t *)malloc(sizeof(pthread_cond_t));
    if (lock->writeOK == NULL)
    {
        free(lock->mut);
        free(lock);
        return (NULL);
    }
    lock->readOK =
        (pthread_cond_t *)malloc(sizeof(pthread_cond_t));
    if (lock->writeOK == NULL)
    {
        free(lock->mut);
        free(lock->writeOK);
        free(lock);
        return (NULL);
    }

    pthread_mutex_init(lock->mut, NULL); // initialises lock's mut variable
    pthread_cond_init(lock->writeOK, NULL);
    pthread_cond_init(lock->readOK, NULL);
    // similarly initialises writeOK and readOK variables of rwl* lock
    lock->readers = 0;
    lock->writers = 0;
    lock->waiting = 0;
    // Initially 0 readers, 0 writers have access to crticial section(shared data) and no processes are waiting hence initialised to 0

    return (lock);
}

void readlock(rwl *lock, int d)
{
    pthread_mutex_lock(lock->mut); // does not allow otther threads to lock mutex named mut

    // Block the reader if any writer is making a change to the shared variable till the writer is
    // having access to shared varibale
    if (lock->writers || lock->waiting)
    {
        do
        {
            printf("reader %d blocked.\n", d);
            pthread_cond_wait(lock->readOK, lock->mut);
            printf("reader %d unblocked.\n", d);
        } while (lock->writers);
    }
    // else increment the number of readers holding the lock variable
    lock->readers++;
    pthread_mutex_unlock(lock->mut);

    return;
}

void writelock(rwl *lock, int d)
{
    // mut locked
    pthread_mutex_lock(lock->mut);
    lock->waiting++;
    // if any reader or write is accesing the shared variable block the current writer that wants to access the variable
    while (lock->readers || lock->writers)
    {
        printf("writer %d blocked.\n", d);
        pthread_cond_wait(lock->writeOK, lock->mut);
        printf("writer %d unblocked.\n", d);
    }
    // else(if while condition is not true),allow the writer to get access to shared variable and decrement the current number of processess waiting
    lock->waiting--;
    lock->writers++;
    // incrment
    pthread_mutex_unlock(lock->mut);
    return;
}

void readunlock(rwl *lock)
{
    pthread_mutex_lock(lock->mut);
    // derement the number of readers
    lock->readers--;
    if (lock->readers == 0)
        pthread_cond_broadcast(lock->writeOK);
    // if no readers are reading,signal the writer to perform its task
    pthread_mutex_unlock(lock->mut); // mut unlocked
}

void writeunlock(rwl *lock)
{
    pthread_mutex_lock(lock->mut);
    // decrement the writer variable indicating currently writer of that particular thread has finished its task
    lock->writers--;
    // signalling all readers using (cond_broadcast) to read the data now as writer has finished
    pthread_cond_broadcast(lock->readOK);
    pthread_mutex_unlock(lock->mut); // unlock the mutex
}

// All the threads have finished thier execution, delete the lock that was created
void deletelock(rwl *lock)
{
    pthread_mutex_destroy(lock->mut);
    pthread_cond_destroy(lock->readOK);
    pthread_cond_destroy(lock->writeOK);
    free(lock);

    return;
}