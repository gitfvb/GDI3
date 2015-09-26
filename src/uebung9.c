//20.01.2010: die 2 wörter werden nun als parameter übergeben anstatt
//scanf zu benutzen

#include <stdio.h>

int isSameBackwards(const char *a, const char *b) {

	//initialisierung der zeiger und einiger hilfsvariablen
	char *pointerA = &a[0];
	int bLaenge = laenge(b);
	int aLaenge = laenge(a);
	char *pointerB = &(b[laenge(b)-1]);
	int i = 0;
	int j = laenge(b)-1;

	//wenn die länge eines wortes anders ist als des anderen
	//gib dies aus und brich das programm ab
	if (bLaenge != aLaenge) {
		printf("die wörter sind nicht gleich lang!!!");
		return 0;
	}

	//solange die pointer nicht ins nichts laufen
	while (i <= laenge(a)-1 || j >= 0) {

	// speicher die characters, auf die aktuell gezeigt wird
	char actualA = *pointerA;
	char actualB = *pointerB;

	//wenn die aktuellen characters nicht übereinstimmen, sag das
	//dem benutzer und brich das programm ab
	if (pointerA != pointerB) {
		printf("\n");
		printf("%s", a);
		printf(" rückwärts gelesen ergibt nicht ");
		printf("%s", b);
		return 0;
	}

	//erhöhe bzw. erniedrige die pointer und die hilfszähler,
	//so dass die wörter durchlaufen werden
	*pointerA++;
	i++;
	*pointerB--;
	j--;
	}

	//wenn du alles durchgegangen bist, gib aus, dass das eine wort
	//rückwärts gelesen das gleiche ergibt wie das andere
	printf("\n");
	printf("%s", a);
	printf(" rückwärts gelesen ergibt SEHR WOHL ");
	printf("%s", b);
	printf("!!!");
	return 0;
}


//hilfsfunktion zur berechnung eines char arrays
//indem du es durchgehst, bis du das ende \0 gefunden hast
int laenge(char *s) {
	if(*s==0) return 0;
	char *p = s;
	while (*p != '\0')
		p++;
	return (p - s);
}



int main9(int argc, char *argv[]) {
	//falls mehr als 2 parameter übergeben werden, brich ab
	//argc[1] ist der programmname
	if (argc != 3) {
		printf("fehler, bitte 2 worte als parameter einbeben!!");
		return 0;
	}
	//aufruf der hauptfunktion
	isSameBackwards(argv[1], argv[2]);
	return 0;
}
