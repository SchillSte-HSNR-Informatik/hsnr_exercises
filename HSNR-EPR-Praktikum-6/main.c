#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000

///definiere struct mit Name und Nummer der Studierenden
typedef struct{
    int matrikelNummer;
    char *name;
}studs;

///gibt Liste der Studierenden aus
void ausgebenStudierende(studs *s[], int anzahl){
    printf("\nListe der Studierenden\n"
                   "Matrikelnummer: \t Name:");
    for (int i=0; i<anzahl;i++){
        printf("\n%d \t %s", s[i]->matrikelNummer, s[i]->name);
    }
}

///keine Übergabe bisheriger Werte?
///Diese Funktion löscht alle vorherigen Eingaben.
studs *dateneinlesen(){
    studs *stud = (studs *) malloc (sizeof(stud) *5);
    printf ("matrikel und namen eingeben");
    for (int i = 0; i<5; i++){
        int a;
        char c[16];
        scanf("%d",&a);
        stud[i].matrikelNummer=a;
        scanf("%15s",&c);
        stud[i].name = strdup(c); //strdup funktion stellt Speicherplatz mit malloc bereit, kopiert Inhalt von c dorthin
        //und liefert einen Pointer zurück
    }
    return stud;
}

///Suche Nummer in Feld, gebe Stelle zurueck
///-1 = nicht gefunden
int sucheNachNummer(studs *s[], int anzahl, int matrikelNummer){
    for (int i=0; i<anzahl; i++) {
        if (matrikelNummer == s[i]->matrikelNummer) return i;
    }
    return -1;
}

///Suche Name in Feld, gebe stelle zurueck
///-1 = nicht gefunden
int sucheNachName(studs *s[], int anzahl, char *name){
    for (int i=0; i<anzahl; i++){
        if (strcmp(name, s[i]->name)==0) return i;
    }
    return -1;
}

///Loesche Eintrag anhand des Indices
void loesche(studs *s[], int *anzahl, int stelle){
    for (int i=stelle; i<anzahl-1; i++){
        s[i] = s[i+1];
    }
    *anzahl = *anzahl-1;
}

///Sortierung mit Quicksort
void sortiereAbsteigendNachName(studs *s[], int anzahl){

}

int *zahleneinlesen(){
    int *a = (int *) malloc (sizeof(int) * 5);
    int i = 0;
    printf("zahlen eingeben:");
    for (int i=0; i<5; i++){
        int temp;
        scanf("%d",&temp);
        a[i]=temp;
    }
    return a;
}

char **nameneinlesen(){
    char **c = (char **) malloc (sizeof(char *) *5);
    int i = 0;
    printf("namen eingeben:");
    for (int i = 0; i<5; i++){
        char temp[16];
        scanf("%15s", &temp);
        c[i] = strdup(temp);
//        for (int j = 0; j<i; j++){
//            printf("%s  ",c[j]);
//        }
//        printf("\n***********************\n");
    }
//    for (int j = 0; j<5; j++){
//        printf("%s  ",c[j]);
//    }
    return c;
}
///Hauptmenue
int main() {
    int anzahl=0;
    //ausgebenStudierende(stud, anzahl);
    //loesche (stud, &anzahl, 5);
    //sucheNachName(stud, anzahl, 'fkjansf');

//    int *a;
//    a = zahleneinlesen();
//    for (int i = 0; i<5; i++){
//        printf("%d  ",a[i]);
//    }
//    printf("\n***********************\n");
//    a = realloc (a, 3*sizeof(int));
//    for (int i = 0; i<5; i++){
//        printf("%d  ",a[i]);
//    }
//    printf("\n***********************\n");
//    a = realloc (a, 8*sizeof(int));
//    for (int i= 0; i<8; i++){
//        printf("%d  ",a[i]);
//    }


//    char **c;
//    c = nameneinlesen();
//    for (int i = 0; i<5; i++){
//        if(c[i] != NULL) printf("%s  ",c[i]);
//    }
//    printf("\n***********************\n");
//    c = realloc(c, sizeof(char *) *3);
//    for (int i = 0; i<5; i++){
//        if(c[i] != NULL) printf("%s  ",c[i]);
//    }
//    printf("\n***********************\n");
//    c = realloc(c, sizeof(char *)*5);
//    c[3]="harrharr";
//    c[4]="askjfnas!";
//    for (int i = 0; i<5; i++){
//        if(c[i] != NULL) printf("%s  ",c[i]);
//    }
//    printf("\n***********************\n");
    //system("PAUSE");
    //printf("%s", c[7]); // Zugriff auf undefinierte pointer -> doof, segfault
//    if (c[7] == NULL) printf("pointer is Null");
//    else printf("pointer c[7] is %d", &c[7]);
//    c[7] = "ajknfkjanf";
//    printf("in c[7] steht jetzt: %s", c[7]);

    studs *stud; // sollte enthalten: *int, **char
    stud = dateneinlesen();
    for (int i = 0; i<5; i++){
        printf("\n%d | %s",stud[i].matrikelNummer, stud[i].name);
    }
    printf("\n***********************\n");
    system("PAUSE");
}