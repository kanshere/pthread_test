#include <stdio.h>
#include <pthread.h>

#define THREADS_COUNT 10

void print_hello (char * name)
{
    printf("Hello %s\n", name);
    pthread_exit(NULL);
}

int main ()
{
    pthread_t threads[THREADS_COUNT];

    int i;
    
    for (i = 0; i < THREADS_COUNT; i ++) {
        pthread_create(&threads[i], NULL, print_hello, "Noone");
    }
    
    for (i = 0; i < THREADS_COUNT; i++) {
        pthread_join(threads[i], NULL);
    }
    
    return (0);
}