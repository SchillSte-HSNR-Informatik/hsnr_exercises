#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000

///definiere struct mit Name und Nummer der Studierenden
/// setze typedef ein
typedef struct{
    int matrikelNummer;
    char *name;
} students;

///gibt Liste der Studierenden aus
void ausgebenStudierende(students *st, int anzahl){
    for (int i=0; i<anzahl; i++){
        printf("\n%d", (st+i)->matrikelNummer);
    }
    for (int i=0; i<anzahl; i++){
        printf("\n%s", (st+i)->name);
    }
    return;
}

///keine Übergabe bisheriger Werte?
///Diese Funktion löscht alle vorherigen Eingaben.
char **chareinlesen() {
    char **tage;
    tage = (char**) calloc(3,sizeof(char*));
    tage[0] = (char*) malloc((strlen("Montag")+1) * sizeof(char));
    strcpy(tage[0], "Montag");
    tage[1] = (char*) calloc(strlen("Dienstag")+1, sizeof(char));
    strcpy(tage[1], "Dienstag");
    tage[2] = (char*) calloc(1, sizeof("Mittwoch"));
    strcpy(tage[2], "Mittwoch");
    return tage;
}

int *tageinlesen(){
    int *tag;
    tag = (int *) calloc (3, sizeof(int*));
    tag[0]=1;
    tag[1]=3;
    tag[2]=58;
    return tag;
}

void ausgabe(char **tage, int *tag, int anzahl){
    for (int i=0; i<anzahl; i++){
        printf("\n%d, %s", *(tag+i), *(tage+i));
    }
}

students *dateneinlesen(){
    students *daten;
    return daten;
}

///Hauptmenue
int main() {
    int *a;
    a = (int *) malloc( 5 * sizeof(int));
    int b[] = {1,2,3,4,5};
    a = b;
    for (int i=0; i<5;i++) printf("\n%d", a[i]);
    a = (int *) realloc (a, 10*sizeof(int));
    for (int i=0; i<5;i++) printf("\n%d", a[i]);
    

}