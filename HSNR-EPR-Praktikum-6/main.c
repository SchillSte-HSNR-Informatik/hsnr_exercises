#include <stdio.h>
#include <string.h>
#define MAX 1000

///definiere struct mit Name und Nummer der Studierenden
struct studierende{
    int matrikelNummer;
    char name;
};

///gibt Liste der Studierenden aus
void ausgebenStudierende(struct studierende *s[], int anzahl){
    printf("\nListe der Studierenden\n"
                   "Matrikelnummer: \t Name:");
    for (int i=0; i<anzahl;i++){
        printf("\n%d \t %s", s[i]->matrikelNummer, s[i]->name);
    }
}

///keine Übergabe bisheriger Werte?
///Diese Funktion löscht alle vorherigen Eingaben.
struct studierende *dateneinlesen(){
    struct studierende *stud;
    return stud;
}

///Suche Nummer in Feld, gebe Stelle zurueck
///-1 = nicht gefunden
int sucheNachNummer(struct studierende *s[], int anzahl, int matrikelNummer){
    for (int i=0; i<anzahl; i++) {
        if (matrikelNummer == s[i]->matrikelNummer) return i;
    }
    return -1;
}

///Suche Name in Feld, gebe stelle zurueck
///-1 = nicht gefunden
int sucheNachName(struct studierende *s[], int anzahl, char *name){
    for (int i=0; i<anzahl; i++){
        if (strcmp(name, s[i]->name)==0) return i;
    }
    return -1;
}

///Loesche Eintrag anhand des Indices
void loesche(struct studierende *s[], int *anzahl, int stelle){
    for (int i=stelle; i<anzahl-1; i++){
        s[i] = s[i+1];
    }
    *anzahl = *anzahl-1;
}

///Sortierung mit Quicksort
void sortiereAbsteigendNachName(struct studierende *s[], int anzahl){

}

///Hauptmenue
int main() {
    struct studierende stud[MAX];
    int anzahl=0;
    ausgebenStudierende(stud, anzahl);
    loesche (stud, &anzahl, 5);
    sucheNachName(stud, anzahl, 'fkjansf');
}