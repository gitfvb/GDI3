
#include <pthread.h>
#include <stdio.h>

void *thread1235(void *threadid)
{
     printf("Das ist Thread %d.\n", (int)threadid);
     pthread_exit(NULL);
}


int mainaaa(int argc, char *argv[])
{
// Zwei Threads erzeugen, die mit der Funktion "thread" starten.
   pthread_t threads[2];
   pthread_create(&threads[0], NULL, thread1235, (void *) 0);
   pthread_create(&threads[1], NULL, thread1235, (void *) 1);

   // Auf das Ende beider Threads warten
   pthread_join(threads[0], NULL);
   pthread_join(threads[1], NULL);

   printf("Alle Threads wurden beendet.\n");

   //system("PAUSE");
   return 0;
}
