#include <stdio.h>

#define MAX 10
///gibt matrizen aus
int matrixAusgeben(double mat[][MAX], int zeilen, int spalten){
    for(int i=0; i < zeilen; i++) {
        printf("\n");
        for (int j = 0; j < spalten; j++) {
            printf(" %6.2lf", mat[i][j]);
        }
    }
    return 1;
}

///eingabe fuer elemente der matrizen
int matrixEingeben(double mat[][MAX], int zeilen, int spalten){
    printf("\nWert eingeben fuer...\n");
    for(int i=0; i < zeilen; i++) {
        for(int j=0; j < spalten; j++) {
            printf("(%d, %d): ", i, j);
            scanf("%lf", &mat[i][j]);
        }
    }
    return 1;
}

///addiert Matrizen
int matrixAddieren( double mat1[][MAX], double mat2[][MAX], int zeilen, int spalten){
    //ergebnismatrix anlegen
    double resMat[MAX][MAX];
    //elemente berechnen
    for(int i=0; i < zeilen; i++) {
        for (int j = 0; j < spalten; j++) {
            resMat[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    //ergebnismatrix ausgeben
    printf("\nErgebnis:");
    matrixAusgeben(resMat, zeilen, spalten);
    return 1;
}

///berechnet skalarprodukt / inneres produkt von 2 vektoren
double skalarProdukt(const double a[], const double b[], int n){
    double result=0.0;

    for (int i = 0; i < n; i++) {
        result += a[i]*b[i];
    }
    return result;
}

///liest eine spalte einer matrix und schreibt sie in einen vektor
///input mat matrix
///input j index der spalte
///output spalte
int matrixSpalte(double mat[][MAX], int j, double spalte[10]){
    for (int i=0; i<10;i++){
        spalte[i]=mat[i][j];
    }
    return 1;
}

///initialisiert Matrizen nach Änderung der Spalten-/Zeilenzahl
int matrixZuruecksetzen(double mat1[][MAX], double mat2[][MAX], int zeilen, int spalten){
    for(int i=0; i < zeilen; i++) {
        for(int j=0; j < spalten; j++) {
            mat1[i][j]=mat2[i][j]=0;
        }
    }
    return 0;
}

///Multiplikation von 2 nxn matrizen mit Ergebnisausgabe
int matrixMultiplizieren( double mat1[][MAX], double mat2[][MAX], int zeilen, int spalten){
    //2 matrizen koennen multipliziert werden
    //wenn die spaltenzahl 1 mit der zeilenzahl 2 uebereinstimmt
    //fuer unsere matrizen aus der additionsaufgabe, in die matrizen
    //gleich lang und breit sein mussten ist dies nur der Fall wenn n=m
    if (zeilen != spalten){
        printf("Multiplikation nur für nxn matrizen moeglich");
        return 0;
    }
    //spalten der 2. matrix muessen als zeile uebergeben werden
    double spalte[MAX];
    //Matrix fuer Ergebnis
    double result[MAX][MAX];
    //matrixZuruecksetzen(result, result, zeilen, spalten);
    for (int i=0; i<zeilen; i++){
        for (int j=0; j<spalten;j++){
            matrixSpalte(mat2, j, spalte);
            result[i][j] = skalarProdukt(mat1[i], spalte, zeilen);
        }
    }
    matrixAusgeben(result,zeilen,spalten);
    return 1;
}



///Addiere 2 Matrizen von maximaler Groesse 10x10
int matrixAddition(){
    //kontrollvariablen für menue
    int select=1;
    int eingabe=0;
    int dimensionGueltig=0;

    //Arrays anlegen
    double mat1[MAX][MAX], mat2[MAX][MAX];
    int zeilen=1, spalten=1;
    matrixZuruecksetzen(mat1, mat2, zeilen, spalten);
    printf("\n\nAddition zweier Matrizen"
                   "\n========================");

    while (select) {
        printf("\n\naktuelle Werte: ");
        printf("\nAnzahl Zeilen: %d", zeilen);
        printf("\nAnzahl Spalten: %d", spalten);
        printf("\nMatrix 1: ");
        matrixAusgeben(mat1, zeilen, spalten);
        printf("\nMatrix 2: ");
        matrixAusgeben(mat2, zeilen, spalten);

        printf("\n\n\t(1) Zeilenzahl aendern"
                       "\n\t(2) Spaltenzahl aendern"
                       "\n\t(3) Matrix 1 aendern"
                       "\n\t(4) Matrix 2 aendern"
                       "\n\t(5) Addition ausfuehren"
                       "\n\t(6) Multiplikation ausfuehren"
                       "\n\t(7) Zurueck zur Aufgabennavigation");

        printf("\nAuswahl: ");
        scanf("%d", &eingabe);
        switch(eingabe){
            case 1:
                dimensionGueltig=0;
                while(!dimensionGueltig){
                    printf("\nNeue Zeilenzahl: ");
                    scanf("%d", &zeilen);
                    if (zeilen > 0 && zeilen <= MAX) dimensionGueltig = 1;
                }
                matrixZuruecksetzen(mat1, mat2, zeilen, spalten);
                break;
            case 2:
                dimensionGueltig=0;
                while(!dimensionGueltig){
                    printf("\nNeue Spaltenzahl: ");
                    scanf("%d", &spalten);
                    if (spalten > 0 && spalten <= MAX) dimensionGueltig = 1;
                }
                matrixZuruecksetzen(mat1, mat2, zeilen, spalten);
                break;
            case 3:
                printf("\nMatrix 1 ändern");
                matrixEingeben(mat1, zeilen, spalten);
                break;
            case 4:
                printf("\nMatrix 2 ändern");
                matrixEingeben(mat2, zeilen, spalten);
                break;
            case 5:
                matrixAddieren(mat1, mat2, zeilen, spalten);
                break;
            case 6:
                matrixMultiplizieren(mat1,mat2, zeilen, spalten);
                break;
            case 7:
                select = 0;
                break;
            default:
                printf("\nungueltige Eingabe");
                break;
        }
    }
    return 1;
}


int matrikelNrAnzeigen(int matrikelNummern[1000], int anzahlStudenten){
    printf("\nAktuell eingetragene Matrikelnummern:");
    for (int i=0; i < anzahlStudenten; i++) {
        printf("\n%d: %d", i, matrikelNummern[i]);
    }
    return 1;
}

int matrikelNrSuchen(int matrikelNummern[1000], int anzahlStudenten){
    printf("\nSuche einer Matrikelnummer im Array");
    printf("\nMatrikelnummer: ");
    int gueltig=0;

    int gesuchteNummer=0;
    while (!gueltig){
        scanf("%d", &gesuchteNummer);
        //pruefen ob eingabe korrektes format hat?
        if (gesuchteNummer>0) gueltig = 1;
    }
    for (int i = 0; i < anzahlStudenten; i++){
        printf(".");
        if (matrikelNummern[i] == gesuchteNummer){
            printf("\nMatrikelnummer gefunden an Stelle %d", i);
            return i;
        }
    }
    printf("\n Matrikelnummer nicht im Array enthalten");
    return 1;
}

///fuege nummer hinzu, inkrementiert anzahl
///WICHTIG: ÜBERGABE VON ZEIGER FÜR ANZAHL STUDENTEN!!
int matrikelNrHinzufuegen(int matrikelNummern[1000], int *anzahlStudenten){
    printf("\nMatrikelnummer hinzufuegen: ");
    int gueltig=0;
    int matrikelNummer=0;
    while (!gueltig){
        scanf("%d", &matrikelNummer);
        //pruefen ob eingabe korrektes format hat
        gueltig = 1;
    }
    matrikelNummern[*anzahlStudenten] = matrikelNummer;
    *anzahlStudenten = *anzahlStudenten +1;
    printf("\nNEUE zahl studierender: %d", *anzahlStudenten);

    return 1;
}

int feldLoeschen(int matrikelNummern[1000], int *anzahlStudenten){
    int eingabe=0;
    printf("\nwelches Feld soll geloescht werden?");
    int gueltig=0;
    int matrikelNummer=0;
    while (!gueltig){
        scanf("%d", &eingabe);
        //pruefen ob eingabe korrektes format hat
        if (eingabe < *anzahlStudenten) gueltig = 1;
        else printf("Feld existiert nicht, neue Auswahl: ");
    }
    for (int i = eingabe; i < *anzahlStudenten-1; i++){
        matrikelNummern[i]=matrikelNummern[i+1];
    }
    *anzahlStudenten = *anzahlStudenten -1;
    printf("\nNEUE zahl studierender: %d", *anzahlStudenten);

    return 1;
}

///Verwalte ein Array von Studierenden
int verwaltungStudierende(){
    //kontrollvariablen fuer menue
    int select = 1;
    int eingabe = 0;

    //array fuer matrikelnummern
    int matrikelNummern[1000];
    //zahl der eintraege
    int anzahlStudenten=0;

    printf("\n\nVerwaltung von Studierenden"
                   "\n============================");
    while (select) {
        printf("\naktuelle zahl studierender: %d", anzahlStudenten);
        printf("\n\n\t(1) Matrikelnummern anzeigen"
                       "\n\t(2) Matrikelnummer suchen"
                       "\n\t(3) Matrikelnummer hinzufuegen"
                       "\n\t(4) Feld Loeschen"
                       "\n\t(5) Zurueck zur Aufgabennavigation");
        printf("\nAuswahl: ");
        scanf("%d", &eingabe);
        switch(eingabe){
            case 1:
                matrikelNrAnzeigen(matrikelNummern, anzahlStudenten);
                break;
            case 2:
                matrikelNrSuchen(matrikelNummern, anzahlStudenten);
                break;
            case 3:
                matrikelNrHinzufuegen(matrikelNummern, &anzahlStudenten);
                break;
            case 4:
                feldLoeschen(matrikelNummern, &anzahlStudenten);
                break;
            case 5:
                select = 0;
                break;
            default:
                printf("\nungueltige Eingabe");
                break;
        }
    }
    return 1;
}

///Skalarprodukt zweier Vektoren. Verwendet 1xM matrizen um Funktionen aus der Haupt-Aufgabe weiterzuverwenden
int inneresProdukt(){
    int select=1;
    int eingabe=0;
    int dimensionGueltig=0;

    //Arrays anlegen
    double mat1[1][MAX], mat2[1][MAX];
    int zeilen=1, spalten=1;
    matrixZuruecksetzen(mat1, mat2, zeilen, spalten);
    printf("\n\nInneres Produkt zweier Vektoren"
                   "\n==============================");

    while (select) {
        printf("\n\naktuelle Werte: ");
        //printf("\nAnzahl Zeilen: %d", zeilen);
        printf("\nVektorlaenge: %d", spalten);
        printf("\nVektor 1: ");
        matrixAusgeben(mat1, zeilen, spalten);
        printf("\nVektor 2: ");
        matrixAusgeben(mat2, zeilen, spalten);

        printf("\n\n\t(1) Vektorlaenge aendern"
                       "\n\t(2) Vektor 1 aendern"
                       "\n\t(3) Vektor 2 aendern"
                       "\n\t(4) Skalarprodukt berechnen"
                       "\n\t(5) Zurueck zur Aufgabennavigation");

        printf("\nAuswahl: ");
        scanf("%d", &eingabe);
        switch(eingabe){
            case 1:
                dimensionGueltig=0;
                while(!dimensionGueltig){
                    printf("\nNeue Vektorlaenge: ");
                    scanf("%d", &spalten);
                    if (spalten > 0 && spalten <= MAX) dimensionGueltig = 1;
                }
                matrixZuruecksetzen(mat1, mat2, zeilen, spalten);
                break;
            case 2:
                printf("\nVektor1 ändern");
                matrixEingeben(mat1, zeilen, spalten);
                break;
            case 3:
                printf("\nVektor2 ändern");
                matrixEingeben(mat2, zeilen, spalten);
                break;
            case 4:
                printf("\nSkalarprodukt berechnen");
                printf("\nErgebnis: %5.2lf",skalarProdukt(mat1[0], mat2[0], spalten));
                break;
            case 5:
                select = 0;
                break;
            default:
                printf("\nungueltige Eingabe");
                break;
        }
    }
    return 1;
}

///menue fuer navigation zu einzelnen praktikumsaufgaben
int main() {
    //kontrollvariablen für menue
    int eingabe=0;
    int select=1;

    printf("EPR PRAKTIKUM IV");
    printf("\n================");
    while (select){
        printf("\n\nAufgabennavigation:");
        printf("\n\t(1) Aufgabe 1 Matrix-Addition"
                       "\n\t(2) Aufgabe 2 Verwaltung von Studierenden"
                       "\n\t(3) Aufgabe 3 Inneres Produkt"
                       "\n\t(4) Beende Programm"
                       "\n\tAuswahl: ");
        scanf("%d", &eingabe);
        switch(eingabe) {
            case 1:
                matrixAddition();
                break;
            case 2:
                verwaltungStudierende();
                break;
            case 3:
                inneresProdukt();
                break;
            case 4:
                printf("\nBeende Programm");
                select=0;
                break;
            default:
                printf("\nungueltige Eingabe");
                break;
        }
    }
    return 0;
}