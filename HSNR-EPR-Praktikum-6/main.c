#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000

///struct als neuen type deklarieren
typedef struct{
    int matrikelNummer;
    char *name;
}studs;

///struct aus eingaben zusammenbasteln
studs *dateneinlesen(){
    studs *stud = (studs *) malloc (sizeof(stud) *7);
    printf ("matrikel und namen eingeben");
    for (int i = 0; i<7; i++){
        //Matrikelnr einlesen
        scanf("%d",&stud[i].matrikelNummer);
        //Name einlesen
        char c[16];
        scanf("%15s",&c);
        stud[i].name = strdup(c); //strdup funktion stellt Speicherplatz mit malloc bereit, kopiert Inhalt von c dorthin
        //und liefert einen Pointer zurück
    }
    return stud;
}

///Hauptmenue
int main() {
    studs *stud;
    stud = dateneinlesen();
    for (int i = 0; i<7; i++){
        printf("\n%d | %s",stud[i].matrikelNummer, stud[i].name);
    }
    printf("\n***********************\n");
}