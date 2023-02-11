#include <pthread.h> // Include the pthread library
#include <stdio.h>   // Include the standard input/output library
#include <unistd.h>  // Include the unix library

/* readcount: integer variable to keep track of the number of readers accessing the shared resource */
int readcount = 0;

/* lock: mutex variable to protect the readcount variable */
pthread_mutex_t lock;

/* wrt: mutex variable to ensure that only one writer accesses the shared resource at a time */
pthread_mutex_t wrt;

/*
reader function: function executed by the reader threads
arg: pointer to the reader ID integer
*/
void *reader(void *arg)
{
    /* Convert the pointer to an integer and store it in the local variable "id" */
    int id = *(int *)arg;

    /* Loop indefinitely */
    while (1)
    {
        /* Acquire the lock mutex */
        pthread_mutex_lock(&lock);

        /* Increment the readcount variable */
        readcount++;

        /*
        If this is the first reader accessing the shared resource,
        acquire the wrt mutex to prevent writers from accessing it
        */
        if (readcount == 1)
        {
            pthread_mutex_lock(&wrt);
        }

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

        /*
        If this is the last reader accessing the shared resource,
        release the wrt mutex to allow writers to access it
        */
        if (readcount == 0)
        {
            pthread_mutex_unlock(&wrt);
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
void *writer(void *arg)
{
    /* Convert the pointer to an integer and store it in the local variable "id" */
    int id = *(int *)arg;

    /* Loop indefinitely */
    while (1)
    {
        /* Acquire the wrt mutex */
        pthread_mutex_lock(&wrt);

        /* Print a message indicating that the writer is writing */
        printf("Writer %d is writing\n", id);

        /* Sleep for 100ms to artificially slow down the execution of the thread */
        usleep(100000);

        /* Release the wrt mutex */
        pthread_mutex_unlock(&wrt);

        /* Sleep for 100ms to artificially slow down the execution of the thread */
        usleep(100000);
    }
}

/* Main function */
int main()
{
/* Initialize the lock and wrt mutexes */
pthread_mutex_init(&lock, NULL);
pthread_mutex_init(&wrt, NULL);

/* Array to store the thread IDs */
pthread_t threads[10];

/* Variables to store the reader and writer IDs */
int reader_ids[5] = {1, 2, 3, 4, 5};
int writer_ids[5] = {1, 2, 3, 4, 5};

/* Create the reader and writer threads */
for (int i = 0; i < 5; i++)
{
    pthread_create(&threads[i], NULL, reader, &reader_ids[i]);
    pthread_create(&threads[i + 5], NULL, writer, &writer_ids[i]);
}

/* Wait for all the threads to finish */
for (int i = 0; i < 10; i++)
{
    pthread_join(threads[i], NULL);
}

/* Destroy the lock and wrt mutexes */
pthread_mutex_destroy(&lock);
pthread_mutex_destroy(&wrt);

return 0;
}