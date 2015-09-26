#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define A_SIZE 400

// Eigene Struktur, um Parameter für Threads zu transportieren
typedef struct  {
	int *arr;		// zu sortierender Array
	int start;		// Start-Position der Sortierung
	int end;		// Ende-Position der Sortierung
} slowParams;

// Implementierung von slowsort
int slowsort(int *A, int i, int j) {
    if (i >= j) return 0;   // Rekursionsanker
    int m = (i+j)/2;
    slowsort(A,i,m);
    slowsort(A,m+1,j);
    if (A[j] < A[m]) {      // Vertauschen
       int x = A[j];
       int y = A[m];
       A[j] = y;
       A[m] = x;
    }
    slowsort(A,i,j-1);
    return 0;
}

// Thread-Steuerung zum Anstarten der Sortierung
void *thread(void *p)
{
	slowParams *s;								// variable s erstellen
	s = p;										// zuweisen
	slowsort((*s).arr, (*s).start, (*s).end);	// sortierung anstarten
	pthread_exit(NULL);							// thread beenden
}

int main(int argc, char *argv[])
{

    // Deklaration
    int a[A_SIZE];
    int i;
    int j = A_SIZE - 1;

    // Unsortierte Liste erstellen
    for (i = 0; i < A_SIZE; i++) {
        a[i] = j;
        j--;
    }

    // Parameter-Übergabe für Threads erzeugen
    slowParams t1, t2;

    // Parameter für Thread 1
    t1.arr = a;
    t1.start = 0;
    t1.end = 199;

    // Parameter für Thread 2
    t2.arr = a;
    t2.start = 200;
    t2.end = 399;

	// Zwei Threads erzeugen, die mit der Funktion "thread" starten.
	pthread_t threads[2];
	pthread_create(&threads[0], NULL, thread, (void *) &t1);
	pthread_create(&threads[1], NULL, thread, (void *) &t2);

	// Auf das Ende beider Threads warten
	pthread_join(threads[0], NULL);
	pthread_join(threads[1], NULL);

    // Ausgabe der Liste
    for (i = 0; i < A_SIZE; i++)
        printf("%i ", a[i]);

    // Abschlussarbeiten
    printf("\n\n");
    return 0;
}


