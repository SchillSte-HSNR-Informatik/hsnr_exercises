/* umstapeln.c */
#include <stdio.h>
#define STAB1 1
#define STAB2 2
#define STAB3 3
unsigned int anzahlStapelSchritte = 0;

void umstapeln(unsigned int, unsigned int, unsigned int, unsigned int);

void main(void)
{
/* Daten */
    unsigned int anzahlScheiben = 0;
/* Kern */
    printf("Bitte geben Sie die Anzahl der Scheiben ein: ");
    scanf("%i", &anzahlScheiben);
    umstapeln(anzahlScheiben, STAB1, STAB3, STAB2);
}

void umstapeln(unsigned int nScheibenAufAusgangsStab, unsigned int ausgangsStab, unsigned int zielStab, unsigned int hilfsStab){
/* Beschreibung */
/* rekursive Loesung des Problems „Türme von Hanoi“ */
/* Kern */
    if (nScheibenAufAusgangsStab > 0) {

        umstapeln(nScheibenAufAusgangsStab-1, ausgangsStab, hilfsStab, zielStab);
        anzahlStapelSchritte++;
        printf("%i.Schritt: bewege die Scheibe %c von Stab %2i nach %2i\n",
               anzahlStapelSchritte, 'A'+nScheibenAufAusgangsStab-1,
               ausgangsStab, zielStab);
        umstapeln(nScheibenAufAusgangsStab-1, hilfsStab, zielStab, ausgangsStab);
    }
}