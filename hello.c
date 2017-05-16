#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define NUM_THREADS	5000

int b[1000], c[1000], n=500;

void *PrintHello(void *threadid)
{
   int i, j, a[500];
   long tid;
   tid = (long)threadid;
   printf("Hello World! It's me, thread #%ld!\n", tid);
   for (i=0; i<n; i++){
      a[i] = b[i] + c[i];
    printf("Djay! It's me, thread #%d!\n", a[i]);}
   pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
   pthread_t threads[NUM_THREADS];
   int rc;
   long t;
   int i=0;
   // initialize b & c
   for(i=0;i<1000;i++){
    b[i]=5;
    c[i]=6;
   }

   for(t=0;t<NUM_THREADS;t++){
     printf("In main: creating thread %ld\n", t);
     rc = pthread_create(&threads[t], NULL, PrintHello, (void *)t);
     if (rc){
       printf("ERROR; return code from pthread_create() is %d\n", rc);
       exit(-1);
       }
     }

   /* Last thing that main() should do */
   pthread_exit(NULL);
}
