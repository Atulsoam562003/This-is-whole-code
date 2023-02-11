#include <pthread.h> // Include the pthread library
#include <stdio.h>   // Include the standard input/output library
#include <unistd.h>  // Include the unix library
#include <stdbool.h> // Include the standard boolean library

#define SIMREAD 3 // Maximum number of simultaneous readers before writers have to wait

/* readcount: integer variable to keep track of the number of readers accessing the shared resource */
int readcount = 0;

/* lock: mutex variable to protect the readcount variable */
pthread_mutex_t lock;

/* wrt: mutex variable to ensure that only one writer accesses the shared resource at a time */
pthread_mutex_t wrt;

/* reader_wait: condition variable for waiting readers */
pthread_cond_t reader_wait;

/* writer_wait: condition variable for waiting writers */
pthread_cond_t writer_wait;

/*
reader function: function executed by the reader threads
arg: pointer to the reader ID integer
*/
void *reader(void *arg) {
    /* Convert the pointer to an integer and store it in the local variable "id" */
    int id = *(int *)arg;

    /* Loop indefinitely */
    while (1) {
        /* Acquire the lock mutex */
        pthread_mutex_lock(&lock);

        /* If there are more than SIMREAD readers or a writer is writing, wait */
        while (readcount > SIMREAD || pthread_mutex_trylock(&wrt) == 0) {
            pthread_cond_wait(&reader_wait, &lock);
        }

        /* Increment the readcount variable */
        readcount++;

        /* Release the lock mutex */
        pthread_mutex_unlock(&lock);

        /* Print a message indicating that the reader is reading */
        printf("Reader %d is reading\n", id);

        /* Sleep for 100ms to artificially slow down the execution of the thread */
        usleep(100000);

        /* Acquire the lock mutex */
        pthread_mutex_lock(&lock);

        /* Decrement the readcount variable */
        readcount--;

        /* If this is the last reader accessing the shared resource, wake up a waiting writer */
        if (readcount == 0) {
            pthread_cond_signal(&writer_wait);
        }

        /* Release the lock mutex */
        pthread_mutex_unlock(&lock);

        /* Sleep for 100ms to artificially slow down the execution of the thread */
        usleep(100000);
    }
}

/*
writer function: function executed by the writer threads
arg: pointer to the writer ID integer
*/
void *writer(void *arg) {
    /* Convert the pointer to an integer and store it in the local variable "id" */
    int id = *(int *)arg;

    /* Loop indefinitely */
    while (1) {
        /* Acquire the lock mutex */
        pthread_mutex_lock(&lock);

        /* If there are any readers reading, wait */
        while (readcount > 0) {
            pthread_cond_wait(&writer_wait, &lock);
        }
        /* Acquire the wrt mutex to ensure that only one writer accesses the shared resource at a time */
        pthread_mutex_lock(&wrt);

        /* Print a message indicating that the writer is writing */
        printf("Writer %d is writing\n", id);

        /* Sleep for 100ms to artificially slow down the execution of the thread */
        usleep(100000);

        /* Release the wrt mutex */
        pthread_mutex_unlock(&wrt);

        /* Wake up one waiting reader, if any */
        pthread_cond_signal(&reader_wait);

        /* Sleep for 100ms to artificially slow down the execution of the thread */
        usleep(100000);
    }
}

int main() {
    /* Initialize the lock mutex */
    pthread_mutex_init(&lock, NULL);

    /* Initialize the wrt mutex */
    pthread_mutex_init(&wrt, NULL);

    /* Initialize the reader_wait condition variable */
    pthread_cond_init(&reader_wait, NULL);

    /* Initialize the writer_wait condition variable */
    pthread_cond_init(&writer_wait, NULL);

    /* Define the number of readers and writers */
    int num_readers = 10, num_writers = 5;

    /* Define arrays to store the reader and writer thread IDs */
    pthread_t reader_threads[num_readers];
    pthread_t writer_threads[num_writers];

    /* Define arrays to store the reader and writer IDs */
    int reader_ids[num_readers];
    int writer_ids[num_writers];

    /* Create the reader threads */
    for (int i = 0; i < num_readers; i++) {
        reader_ids[i] = i;
        pthread_create(&reader_threads[i], NULL, reader, &reader_ids[i]);
    }

    /* Create the writer threads */
    for (int i = 0; i < num_writers; i++) {
        writer_ids[i] = i;
        pthread_create(&writer_threads[i], NULL, writer, &writer_ids[i]);
    }

    /* Wait for all reader threads to complete */
    for (int i = 0; i < num_readers; i++) {
        pthread_join(reader_threads[i], NULL);
    }

    /* Wait for all writer threads to complete */
    for (int i = 0; i < num_writers; i++) {
        pthread_join(writer_threads[i], NULL);
    }

    return 0;
}