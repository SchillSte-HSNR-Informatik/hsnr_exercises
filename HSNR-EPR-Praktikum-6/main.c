#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5

///struct als neuen type deklarieren
typedef struct{
    int matrikelNummer;
    char *name;
}students_t;

///struct aus eingaben zusammenbauen
students_t *dateneinlesen(){
    students_t *a;
    a = (students_t *) malloc (sizeof(students_t));
    printf ("matrikelnr eingeben (Abbruch mit '0') ");
    scanf("%d", &a->matrikelNummer);
    //Name nur einlesen falls neuer Eintrag gewuenscht ist(Matrikelnr ungleich 0 war)
    if (a->matrikelNummer != 0) {
        printf("Name eingeben ");
        char c[1000];
        scanf("%999s", c);
        a->name = strdup(c); //strdup funktion stellt Speicherplatz mit malloc bereit, kopiert Inhalt von c dorthin
        //und liefert einen Pointer zurück
    }
    return a;
}

///gesamtes Feld ausgeben
void studierendeAusgeben(students_t *studierende[], int anzahl){
    printf("%15s | %19s\n", "Matrikelnummer", "Name");
    printf("--------------------------------------\n");
    for (int i = 0; i < anzahl; i++){
        printf("|%14d | %19s|\n", studierende[i]->matrikelNummer, studierende[i]->name);
    }
    printf("--------------------------------------\n");
}

///loesche einen eintrag aus dem Feld und ruecke die folgenden auf
void loesche(students_t *studierende[], int *anzahl, int stelle){
    if (stelle >=0  && *anzahl > stelle){
        for (int i=stelle; i<*anzahl; i++){
            studierende[i]=studierende[i+1];
        }
        *anzahl = *anzahl - 1;
    }
    else printf("Eintrag existiert nicht\n");
}


///suche einen namen im feld, gebe seine stelle zurueck
int sucheName(students_t *studierende[], int anzahl, char *name){
    for (int i=0; i<anzahl; i++){
        if (strcmp(studierende[i]->name, name) ==0 ) return i; //fuer identische strings gibt strcmp 0 zurueck
    }
    return -1;
}

///suche eine matrikelnummer im feld, gebe seine stelle zurueck
int sucheNummer(students_t *studierende[], int anzahl, int nummer){
    for(int i=0; i < anzahl; i++){
        if (studierende[i]->matrikelNummer==nummer) return i;
    }
    return -1;

}

int istKleinerNachNummer(students_t *stud1, students_t *stud2){
    return stud2->matrikelNummer-stud1->matrikelNummer; // Ergebnis positiv wenn stud1.matrikelnummer kleinerNachNummer
}

int istGroesserNachNummer(students_t *stud1, students_t *stud2){
    return stud1->matrikelNummer-stud2->matrikelNummer; // Ergebnis positiv wenn stud1.matrikelnummer groesserNachNummer
}

int istKleinerNachName(students_t *stud1, students_t *stud2){
    return strcmp(stud2->name, stud1->name); // Ergebnis positiv wenn stud1.name kleinerNachName
}

int istGroesserNachName(students_t *stud1, students_t *stud2){
    return strcmp(stud1->name, stud2->name); // Ergebnis positiv wenn stud1.name groesserNachName
}

///implementation von quicksort mit strcmp
///quicksort waehlt einen beliebigen wert aus dem Feld, in diesem Fall den mittleren, als pivot und prueft von beiden
///Seiten, ob ein groeßerer/kleinerer Wert vorhanden ist. In diesem Fall werden die Positionen vertauscht.
///Wenn die Pruefung sich in der Mitte getroffen hat, wird rekursiv fuer die Abschnitte links und rechts dasselbe
///Verfahren ausgefuehrt, bis schliesslich alle Werte sortiert sind.
void quicksortNameAb(students_t *studierende[], int left, int right){
    if (left < right){
        int i = left;
        int j = right;

        char *vgl = studierende[(i+j)/2]->name;
        do{
            while (strcmp(studierende[i]->name, vgl) > 0){
                i = i+1;
            }
            while (strcmp(studierende[j]->name, vgl) < 0){
                j = j-1;
            }
            if (i<=j){
                students_t *temp = studierende[i];
                studierende[i] = studierende[j];
                studierende[j] = temp;
                i= i+1;
                j= j-1;
            }
        }while (i < j);
        quicksortNameAb(studierende, left, j);
        quicksortNameAb(studierende, i, right);
    }
}

void quicksortFktPtr (students_t *studierende[], int (*vergleichsFunktion)(students_t *, students_t *), int left, int right){
    if (left < right){
        int i = left;
        int j = right;
        students_t *vgl = studierende[(i+j)/2];
        do{
            while (vergleichsFunktion(studierende[i], vgl) > 0){
                i=i+1;
            }
            while (vergleichsFunktion(studierende[j], vgl) < 0){
                j=j-1;
            }
            if(i<=j){
                students_t *temp = studierende[i];
                studierende[i] = studierende[j];
                studierende[j] = temp;
                i = i+1;
                j = j-1;
            }
        }while (i<j);
        quicksortFktPtr(studierende, vergleichsFunktion, left, j);
        quicksortFktPtr(studierende, vergleichsFunktion,  i, right);
    }
}

///Sortierung nach Name und Nummer, mit Uebergabe von Fktspointer
void sortiereAbsteigendNachName(students_t *studierende[], int anzahl){
    if (anzahl > 1){
        int left = 0;
        int right = anzahl - 1;
        printf("Sortiert nach Name, absteigend\n");
        quicksortNameAb(studierende, left, right);
        studierendeAusgeben(studierende, anzahl);

        printf("Sortiert nach Name, aufsteigend\n");
        quicksortFktPtr(studierende, istKleinerNachName, left, right);
        studierendeAusgeben(studierende, anzahl);

        printf("sortiert nach Name, absteigend\n");
        quicksortFktPtr(studierende, istGroesserNachName, left, right);
        studierendeAusgeben(studierende, anzahl);

        printf("sortiert nach Nummer, aufsteigend\n");
        quicksortFktPtr(studierende, istKleinerNachNummer, left, right);
        studierendeAusgeben(studierende, anzahl);

        printf("sortiert nach Nummer, absteigend\n");
        quicksortFktPtr(studierende, istGroesserNachNummer, left, right);
        studierendeAusgeben(studierende, anzahl);
    }
}

int main() {
    students_t *student;
    // Platz für 1. Eintrag schaffen. Laut Aufgabenstellung sollte direkt Platz für 1000 vorgesehen werden - warum?
    students_t **immatrikuliert = (students_t **) malloc (sizeof (students_t *));
    int anzahl = 0;
    int running = 1;
    do{
        student = dateneinlesen();
        if (student->matrikelNummer!=0 ) { //wenn Matrikelnummer nicht 0 ist:
            if (sucheNummer(immatrikuliert, anzahl, student->matrikelNummer) != -1) {
                printf("Diese Matrikelnummer ist bereits eingetragen\n");
            }
            else{
                immatrikuliert = realloc (immatrikuliert, (anzahl+1)*sizeof(students_t *)); //speicherplatz für vorhandene + naechsten Eintrag reservieren
                immatrikuliert[anzahl++] = student; //neuen Eintrag hinzufügen, anzahl erhöhen
            }
        }
        else running = 0;
    } while (running && anzahl < MAX);

    //ungenutzten letzten platz freigeben
    //immatrikuliert = realloc (immatrikuliert, anzahl*sizeof(students_t *));
    //studierendeAusgeben(immatrikuliert, anzahl);

    //Navigation
    running = 1;
    do{
        //menue
        int a;
        int stelle=-1;
        char n[1000];
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
                //Alle Eintraege ausgeben
                if (anzahl < 1) {
                    printf("Die Liste ist leer \n");
                    break;
                }
                studierendeAusgeben(immatrikuliert, anzahl);
                break;
            case 2:
                if (anzahl < 1) {
                    printf("Die Liste ist leer \n");
                    break;
                }
                //Eintrag nach Index loeschen
                printf("\nWelche Stelle soll geloescht werden? ");
                scanf("%d", &stelle);
                loesche(immatrikuliert, &anzahl, stelle);
                //printf("neue Anzahl: %d", anzahl);
                break;
            case 3:
                //Eintrag hinzufuegen
                if (anzahl<MAX){
                    student = dateneinlesen();
                    if (student->matrikelNummer != 0) { //wenn Matrikelnummer nicht 0 ist:
                        if (sucheNummer(immatrikuliert, anzahl, student->matrikelNummer) != -1) {
                            printf("Diese Matrikelnummer ist bereits eingetragen\n");
                        }
                        else {
                            immatrikuliert = (students_t **) realloc(immatrikuliert,
                                             (anzahl + 1) * sizeof(students_t *)); //speicherplatz für vorhandene + naechsten Eintrag reservieren
                            immatrikuliert[anzahl++] = student; //neuen Eintrag hinzufügen, anzahl erhöhen
                        }

                    }
                }
                else printf ("Es sind keine weiteren Eintraege moeglich - das Maximum ist %d\n", MAX);
                break;
            case 4:
                if (anzahl < 1) {
                    printf("Die Liste ist leer \n");
                    break;
                }
                //Feld nach Name durchsuchen und Index ausgeben
                printf("\nNach welchem Namen soll gesucht werden? ");
                scanf("%s", n);
                name = n;
                stelle = sucheName(immatrikuliert, anzahl, name);
                if (stelle >-1) printf("Der gesuchte Name steht an Stelle %d der Liste\n", stelle);
                else printf("Der gesuchte Name wurde nicht gefunden\n");
                break;
            case 5:
                if (anzahl < 1) {
                    printf("Die Liste ist leer \n");
                    break;
                }
                //Feld nach Matrikelnummer durchsuchen und Index ausgeben
                printf("\nNach welcher Matrikelnummer soll gesucht werden? ");
                scanf("%d", &stelle);
                stelle = sucheNummer(immatrikuliert, anzahl, stelle);
                if (stelle >-1) printf("Die gesuchte Matrikelnummer steht an Stelle %d der Liste\n", stelle);
                else printf("Die gesuchte Matrikelnummer wurde nicht gefunden\n");
                break;
            case 6:
                if (anzahl < 1) {
                    printf("Die Liste ist leer \n");
                    break;
                }
                //in der ursprünglichen Sortierfunktion werden alle vorgeschlagenen Sortierungen nacheinander
                //ausgeführt und ausgegeben.
                sortiereAbsteigendNachName(immatrikuliert, anzahl);
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