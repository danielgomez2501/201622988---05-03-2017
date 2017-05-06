 #include <pthread.h>
 #include <stdio.h>
 #include <stdlib.h>
 #define NUM_THREADS     10

 void *Hola(void *threadid)
 {
	int num;
	num = pthread_self();	
    printf("Hola %d\n", num);
    pthread_exit(NULL);
 }

 int main (int argc, char *argv[])
 {
    pthread_t threads[NUM_THREADS];
    int rc;
    long t;
	int id;
	id = pthread_self();
	printf ("Hola soy el principal %d\n", id);
    for(t=0; t<NUM_THREADS; t++){
       rc = pthread_create(&threads[t], NULL, Hola, (void *)t);
       if (rc){
          printf("ERROR; El codigo de retorno de pthread_create() es %d\n", rc);
          exit(-1);
       }
    }

    pthread_exit(NULL);
 }
