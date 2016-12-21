#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000

///struct als neuen type deklarieren
typedef struct{
    int matrikelNummer;
    char *name;
}studs;

///struct aus eingaben zusammenbauen
studs *dateneinlesen(){
    studs *a;
    a = (studs *) malloc (sizeof(studs));
    printf ("matrikelnr eingeben (Abbruch mit '0') ");
    scanf("%d", &a->matrikelNummer);
    //Name nur einlesen falls neuer Eintrag gewuenscht ist(Matrikelnr ungleich 0 war)
    if (a->matrikelNummer != 0) {
        printf("Name eingeben ");
        char c[16];
        scanf("%15s", &c);
        a->name = strdup(c); //strdup funktion stellt Speicherplatz mit malloc bereit, kopiert Inhalt von c dorthin
        //und liefert einen Pointer zurück
    }
    return a;
}

///gesamtes Feld ausgeben
void studierendeAusgeben(studs *studierende[], int anzahl){
    printf("%15s | %19s\n", "Matrikelnummer", "Name");
    printf("--------------------------------------\n");
    for (int i = 0; i < anzahl; i++){
        printf("|%14d | %19s|\n", studierende[i]->matrikelNummer, studierende[i]->name);
    }
    printf("--------------------------------------\n");
}

///loesche einen eintrag aus dem Feld und ruecke die folgenden auf
void loesche(studs *studierende[], int *anzahl, int stelle){
    for (int i=stelle; i<*anzahl; i++){
        studierende[i]=studierende[i+1];
    }
    *anzahl = *anzahl - 1;
}

///suche einen namen im feld, gebe seine stelle zurueck
int sucheName(studs *studierende[], int anzahl, char *name){
    for (int i=0; i<anzahl; i++){
        printf("vergleich %s und %s\n", studierende[i]->name, name);
        if (strcmp(studierende[i]->name, name) ==0 ) return i; //fuer identische strings gibt strcmp 0 zurueck
    }
    return -1;
}

///suche eine matrikelnummer im feld, gebe seine stelle zurueck
int sucheNummer(studs *studierende[], int anzahl, int nummer){
    for(int i=0; i < anzahl; i++){
        if (studierende[i]->matrikelNummer==nummer) return i;
    }
    return -1;

}


int main() {
    studs *student;
    // Platz für 1. Eintrag schaffen. Laut Aufgabenstellung sollte direkt Platz für 1000 vorgesehen werden - warum?
    studs **immatrikuliert = (studs **) malloc (sizeof (studs *));
    int anzahl = 0;
    int running = 1;
    do{
        student = dateneinlesen();
        if (student->matrikelNummer!=0) { //wenn Matrikelnummer nicht 0 ist:
            immatrikuliert = realloc (immatrikuliert, (anzahl+1)*sizeof(studs *)); //speicherplatz für vorhandene + naechsten Eintrag reservieren
            immatrikuliert[anzahl++] = student; //neuen Eintrag hinzufügen, anzahl erhöhen

        }
        else running = 0;
    } while (running && anzahl < 1000);

    //ungenutzten letzten platz freigeben
    //immatrikuliert = realloc (immatrikuliert, anzahl*sizeof(studs *));
    studierendeAusgeben(immatrikuliert, anzahl);

    //Navigation
    running = 1;
    do{
        //menue
        int a;
        int stelle=-1;
        char n[20];
        char *name;
        printf("\n\nHauptmenue\n----------\n");
        printf("(1) Studierende Anzeigen "
                       "(2) Eintrag Loeschen "
                       "(3) Eintrag hinzufuegen \n"
                       "(4) Suche nach Name "
                       "(5) Suche nach Matrikelnummer "
                       "(6) Eintraege sortieren \n"
                       "(7) Ende: ");
        scanf("%d", &a);
        switch(a) {
            case 1:
                studierendeAusgeben(immatrikuliert, anzahl);
                break;
            case 2:
                printf("\nWelche Stelle soll geloescht werden? ");
                scanf("%d", &stelle);
                if (stelle != -1) loesche(immatrikuliert, &anzahl, stelle);
                printf("neue Anzahl: %d", anzahl);
                break;
            case 3:
                student = dateneinlesen();
                if (student->matrikelNummer != 0) { //wenn Matrikelnummer nicht 0 ist:
                    immatrikuliert = realloc(immatrikuliert, (anzahl + 1) *
                                                             sizeof(studs *)); //speicherplatz für vorhandene + naechsten Eintrag reservieren
                    immatrikuliert[anzahl++] = student; //neuen Eintrag hinzufügen, anzahl erhöhen

                }
                break;
            case 4:
                printf("\nNach welchem Namen soll gesucht werden? ");
                scanf("%20s", &n);
                name = n;
                stelle = sucheName(immatrikuliert, anzahl, name);
                if (stelle >-1) printf("Der gesuchte Name steht an Stelle %d der Liste\n", stelle);
                else printf("Der gesuchte Name wurde nicht gefunden\n");
                break;
            case 5:
                printf("\nNach welcher Matrikelnummer soll gesucht werden? ");
                scanf("%d", &stelle);
                stelle = sucheNummer(immatrikuliert, anzahl, stelle);
                if (stelle >-1) printf("Die gesuchte Matrikelnummer steht an Stelle %d der Liste\n", stelle);
                else printf("Die gesuchte Matrikelnummer wurde nicht gefunden\n");
                break;
            case 6:
                break;
            case 7:
                running = 0;
                break;
            default:
                printf("\nungueltige Eingabe!\n");
                break;
        }
    }while (running);
}