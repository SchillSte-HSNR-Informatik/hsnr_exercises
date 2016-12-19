#include <stdio.h>

///Wechselkurs von Euro nach Dollar
double kurs = 1.3810095;

///multipliziert einen Eingangswert mit dem Wechselkurs
///Eingang Euro [double]
///Rückgabe Dollar [double]
double euro2dollar(double euro)
{
    return euro*kurs;
}

///teilt einen Eingangswert durch den Wechselkurs
///Eingang: dollar [double]
///Rückgabe: Euro [double]
double dollar2euro(double dollar)
{
    return dollar/kurs;
}

///rechnet neutrale Eingangswert zwischen Start- und Endwert  von Dollar in Euro bzw Euro in Dollar um
///und gibt die Ergebnisse in Tabellenform aus
///Eingang: Startwert, Endwert, Schrittweite [double]
void printTable(double s, double e, double dt)
{
    //startwert behalten, mit Tabelle mit "betrag" berechnen
    double betrag = s;
    printf("   Euro |  Dollar         Dollar |    Euro\n"
                   "--------+--------        --------+--------");
    while (betrag<e)
    {
        // 7 + 1 Leerzeichen = 8 Stellen für durchgängig formatierte Tabelle
        printf("\n%7.2lf | %7.2lf %14.2lf | %7.2lf", betrag, euro2dollar(betrag), betrag, dollar2euro(betrag));
        betrag += dt;
    }
    //letzte ausgabe
    printf("\n%7.2lf | %7.2lf %14.2lf | %7.2lf", e, euro2dollar(e), e, dollar2euro(e));

}

///gibt die Zahl der Monate im Jahr zurück (konstant, [int])
int monateImJahr()
{
    return 12;
}

///gibt Anzahl der tage in einem gegebenen Monat zurück
///Eingang: Monat, Jahr [int]
///Rückgabe: Tage in diesem Monat [int]
int tageImMonat(int monat, int jahr) {
    switch (monat) {
        case 1:
            return 31;
        case 2:
            if ((jahr % 4) == 0 && (jahr % 100) != 0 || (jahr % 400 == 0)) {
                return 29;
            } else {
                return 28;
            }
        case 3:
            return 31;
        case 4:
            return 30;
        case 5:
            return 31;
        case 6:
            return 30;
        case 7:
            return 31;
        case 8:
            return 31;
        case 9:
            return 30;
        case 10:
            return 31;
        case 11:
            return 30;
        case 12:
            return 31;
        default:
            return 0;
    }
}

///prüft ein Datum darauf, ob es im Kalender enthalten ist.
///Eingang: Tag, Monat, Jahr [int]
///Rückgabe: 0 (false) oder 1 (true) [int]
int datumValidieren(int tag, int monat, int jahr)
{
    int res = 1;
    if ( monat < 0 || monat > monateImJahr())
    {
        printf("... Monat ist nicht gültig");
        res= 0;
    }
    if (tag <= 0 || tag >31) {
        printf("... Tag ist nicht gültig");
        res = 0;
    }
    if (res && tag > tageImMonat(monat, jahr)){
        printf("... Tag ist für Monat %d im Jahr %d nicht gültig", monat, jahr);
        res=0;
    }
    return res;
}

///gibt die Zahl der tage in den nächsten 12 Monaten zurück
///Eingang: monat, jahr [int]
///Rückgabe: tage [int]
int tageImJahr(int monat, int jahr)
{
    int res=0;
    for (int i =0; i <12; i++)
    {
        res+=tageImMonat(monat,jahr);
        monat++;
        if (monat==13) {
            monat=1;
            jahr++;
        }
    }
    return res;
}

///gibt die Zahl der Tage zwischen 2 Daten zurück
///Eingang: tag, monat, jahr, tag2, monat2, jahr2 [int]
///Rückgabe: tag [int]
int tageBisDatum(int tag, int monat, int jahr, int tag2, int monat2, int jahr2)
{
    int res=0;

    //tage jedes Monats bis Zielmonat aufsummieren
    while (monat != monat2)
    {
        res += tageImMonat(monat, jahr);
        monat++;

        if (monat>12)
        {
            monat = 1;
            jahr++;
            //printf("hängts im modulo?!\n");
        }
    }
    //im Dezember angekommen wird die Differenz aus tag und dem 24. zum Resultat addiert.
    res = res + tag2-tag;

    //Falls Jahre verschieden sind, Tage jedes Jahres verrechnen
    if(jahr>jahr2)
    {
        for (int i = 0; i < jahr-jahr2;i++) res = res - tageImJahr(monat, jahr2+i);
    }
    else if (jahr<jahr2){
        for (int i = 0; i < jahr2-jahr; i++) res = res + tageImJahr(monat, jahr+i);
    }

    return res;
}

int main() {
    //variablen für währungsumrechnung - start, ende, schrittweite
    double s, e, dt;
    s=0.0;

    //run variable für while schleifen, die mit Eingabe der ersten var als -1 beendet werden können
    int run =1;

    //Aufgabe 1: Wert einlesen, umrechnen, ausgeben
    printf("Aufgabe 1");
    while (run) {
        printf("\nBitte geben Sie einen Betrag für die Umrechnung ein (Abbruch für -1): ");
        scanf("%lf", &s);
        if (s==-1) break;
        printf("Umrechnung in Euro: %lf", dollar2euro(s));
        printf("\nUmrechnung in Dollar: %lf", euro2dollar(s));
    }

    //Aufgabe 2: Wertbereich einlesen, umrechnen, als Tabelle ausgeben
    printf("\n\nAufgabe 2");
    while (run) {
        printf("\nBitte geben sie einen Startwert ein (Abbruch für -1): ");
        scanf("%lf", &s);
        if (s==-1) break;
        printf("Bitte geben Sie einen Endwert ein: ");
        scanf("%lf", &e);
        printf("Bitte geben Sie die Schrittweite ein: ");
        scanf("%lf", &dt);
        printTable(s, e, dt);
    }

    //Aufgabe 3: Datum einlesen und prüfen
    printf("\n\nAufgabe 3");
    int tag, monat, jahr;
    tag = 0;
    while (run) {
        printf("\nBitte Datum eingeben (Abbruch für Tag -1)\nTag: ");
        scanf("%d", &tag);
        if (tag == -1) break;
        printf("Monat: ");
        scanf("%d", &monat);
        printf("Jahr: ");
        scanf("%d", &jahr);

        //Prüfung
        printf("Eingegebenes Datum %d.%d.%d wird geprüft", tag, monat, jahr);
        if (datumValidieren(tag, monat, jahr)) {
            //Tage bis Weihnachten bestimmen und ausgeben
            int tag2 = 24, monat2 = 12, jahr2 = jahr;
            if (tag > 24 && monat == 12) jahr2++;
            printf("... ist ein gültiges Datum");
            printf("\nEs sind noch %d Tage bis Weihnachten", tageBisDatum(tag, monat, jahr, tag2, monat2, jahr2));

            //Weiteres Datum einlesen, Tage zwischen Datum 1 und 2 bestimmen+ausgeben
            do {
                printf("\n\nBitte weiteres gültiges Datum eingeben\nTag: ");
                scanf("%d", &tag2);
                printf("Monat: ");
                scanf("%d", &monat2);
                printf("Jahr: ");
                scanf("%d", &jahr2);
            } while (!datumValidieren(tag2, monat2, jahr2));
            printf("Das zweite Datum ist %d Tage vom ersten entfernt",
                   tageBisDatum(tag, monat, jahr, tag2, monat2, jahr2));
        }
    }

    return 0;
}