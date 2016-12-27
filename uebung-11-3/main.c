/* tiefensuche.c
 *
 * (copy-paste from exercise to verify results)
 * unclear: why is the "traveling salesman" interested
 * in the result of this depth search?
 * Wouldn't he rather travel the least distance or time?*/
#include <stdio.h>
#include <string.h>

#define MAXKNOTEN 13

/* Daten eines Knotenelementes und Definition eines Listentyps KNOTEN */
typedef struct knoten
{
    int knotenNummer, besucht, dfsNummer;
    char NameStadt[32];
}KNOTEN;

/* Definition der globalen Variablen "KnotenVektor" */
KNOTEN KnotenVektor[MAXKNOTEN];

/* Initialisieren einer einzelnen Vektorkomponente */
void neuerKnoten(int nummer, const char stadt[])
{
    KnotenVektor[nummer-1].knotenNummer = nummer;
    KnotenVektor[nummer-1].besucht = 0;
    KnotenVektor[nummer-1].dfsNummer = 0;
    strcpy(KnotenVektor[nummer-1].NameStadt, stadt);
}

/* Definieren und Initialisieren der Adjazenzmatrix*/
int A_kilometer[MAXKNOTEN][MAXKNOTEN] =
        { { 0, 108, 150, 277, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
          {108, 0, 104, 0, 300, 0, 0, 0, 0, 0, 0, 0, 0 },
          {150, 104, 0, 234, 281, 287, 0, 0, 0, 0, 0, 0, 0 },
          {277, 0, 234, 0, 0, 0, 170, 0, 0, 0, 0, 0, 0 },
          { 0, 300, 281, 0, 0, 262, 0, 68, 0, 0, 0, 0, 0 },
          { 0, 0, 287, 0, 262, 0, 247, 0, 0, 203, 0, 0, 0 },
          { 0, 0, 0, 170, 0, 247, 0, 0, 0, 180, 0, 0, 0 },
          { 0, 0, 0, 0, 68, 0, 0, 0, 191, 0, 0, 0, 0 },
          { 0, 0, 0, 0, 0, 0, 0, 191, 0, 246, 122, 0, 0 },
          { 0, 0, 0, 0, 0, 230, 180, 0, 246, 0, 240, 0, 151 },
          { 0, 0, 0, 0, 0, 0, 0, 0, 122, 240, 0, 135, 283 },
          { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 135, 0, 307 },
          { 0, 0, 0, 0, 0, 0, 0, 0, 0, 151, 283, 307, 0 } };

int dfs1 = 1;

/* Markierungsalgorithmus der Tiefensuche */
void dfs(int v)
{
    int w;
    KnotenVektor[v].besucht = 1;
    KnotenVektor[v].dfsNummer = dfs1;
    dfs1++;;
/* Schleife: Suche nicht markierten Knoten w von v aus */
    for (w = 0; w < MAXKNOTEN; w++)
    {
        if ((A_kilometer[v][w] > 0) && (KnotenVektor[w].besucht == 0))
/* (Es existiert eine Kante von Knoten v zu w) UND (Knoten w
ist noch nicht markiert) */
        {
/* Ausgabe der jeweiligen Kante (v,w) des Spannbaums*/
            printf("(%s, %s)\n", KnotenVektor[v].NameStadt,
                   KnotenVektor[w].NameStadt);
/* Suchen der naechsten Kante ausgehend vom Endknoten
Hochschule	Niederrhein Einführung	in	die	Programmierung Prof.	Dr.	Nitsche
Fachbereich	03 Prof.	Dr.	Davids
Bachelor Informatik WS	2016/17 Blatt	11
S.	7 /	7
der gewählten Kante */
            dfs(w);
        }
    }
}


void main() {
    int i, j;
    neuerKnoten(1, "Hamburg");
    neuerKnoten(2, "Bremen");
    neuerKnoten(3, "Hannover");
    neuerKnoten(4, "Berlin");
    neuerKnoten(5, "Krefeld");
    neuerKnoten(6, "Bad Hersfeld");
    neuerKnoten(7, "Jena");
    neuerKnoten(8, "Koeln");
    neuerKnoten(9, "Frankfurt");
    neuerKnoten(10, "Nuernberg");
    neuerKnoten(11, "Karlsruhe");
    neuerKnoten(12, "Freiburg");
    neuerKnoten(13, "Muenchen");
/* Ausgabe des Knotenvektors*/
    printf("\nKnoten des Graphen:\n");
    for (i = 0; i < MAXKNOTEN; i++){
        printf("Knoten %i = %s, dfsNummer = %i\n",
               KnotenVektor[i].knotenNummer,
               KnotenVektor[i].NameStadt,
               KnotenVektor[i].dfsNummer);
    }
/* Ausgabe der Adjazenzmatrix */
    printf("\nA_kilometer =\n"); /* nur zur Kontrolle */
    for (i = 0; i < MAXKNOTEN; i++){
        for (j = 0; j < MAXKNOTEN; j++){
            printf("%4i ", A_kilometer[i][j]);
        }
        printf("\n");
    }
    printf("\nStartknoten %i = %s\n\n", KnotenVektor[5].knotenNummer,
           KnotenVektor[5].NameStadt);
    printf("Kanten des Spannbaumes:\n");
/* Aufruf der Tiefensuche */
    dfs(11);
/* Ausgabe des Knotenvektors incl. DFS-Besuchsnummern*/
    printf("\nDFS-Nummern der Knoten:\n");
    for (i = 0; i < MAXKNOTEN; i++){
        printf("Knoten %i = %s, dfsNummer = %i\n",
               KnotenVektor[i].knotenNummer,
               KnotenVektor[i].NameStadt,
               KnotenVektor[i].dfsNummer);
    }
}