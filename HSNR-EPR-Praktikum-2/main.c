#include <stdio.h>

/*Praktikum 2
bekannte Probleme:
- prüft nicht ob Eingabe tatsächlich integer Format hat
- kein Sonderfall für 1 (1 ist keine Primzahl)*/

///Primzahl: prüft für eine natürliche Zahl, ob sie Primzahl ist
int Primzahl()
{
    printf("\n\nEPR Praktium 2 - Aufgabe 1: Primzahlen\n");
    printf("Dieser Programmteil fordert zur Eingabe einer Zahl auf, \nprüft ob diese eine Primzahl ist \nund teilt das Ergebnis mit.\n\n");

    int n=0; // integer für einzulesende Zahl
    //Zahl einlesen
    printf("Geben Sie eine natürliche Zahl ein: ( < 1 für abbruch)");
    scanf("%d", &n);
    if (n<1) return 0;

    printf("Prüfung beginnt!\n");
    //Sonderfall n=1 : 1 ist keine Primzahl
    if (n==1) printf("Eingabe %d ist keine Primzahl", n);
    for (int i = 2; i<=n; i++)
    {
        if (n % i == 0 && i !=n)
        {
            printf("Eingabe %d ist keine Primzahl", n);
            break;
        }
        if (i == n) printf("Eingabe %d ist eine Primzahl\n", n);
    }
    return 1;

}

///Primzahlliste: gibt für alle natürlichen Zahlen zwischen a und b aus, ob sie Primzahlen sind
int Primzahlliste()
{
    printf("\n\n=======================================================================");
    printf("\nEPR Praktium 2 - Aufgabe 2: Primzahlliste\n");
    printf("Dieser Programmteil fordert zur Eingabe von zwei ganzen Zahlen a und b auf."
                   "\nFür alle ganzen Zahlen zwischen a und b wird geprüft, ob sie Primzahlen sind."
                   "Das Ergebnis wird als Liste mit zwei Spalten ausgegeben\n\n");

    int n=0, upper=0,lower=0; //zwei weitere Integer um die Grenzen des Zahlenbereichs zu erfassen
    //einlesen
    printf("Geben Sie die erste Zahl ein (<1 für abbruch): ");
    scanf("%d", &lower);
    if (lower < 1) return 0;
    printf("Geben Sie die zweite Zahl ein: ");
    while (n < 1) scanf("%d", &n);

    //Grenzen ordnen
    if (n>lower) upper = n;
    else {
        upper = lower;
        lower = n;
    }

    //Prüfung und Ausgabe
    printf("Prüfung durch for-Schleife mit Modulo Funktion beginnt!\n"
                   "Zahl | Primzahl?\n"
                   "----------------");
    for (n = lower; n<=upper; n++)
    {
        printf("\n%4d | ", n);
        for (int i = 2; i <= n; i++)
        {
            if (n % i == 0 && i!=n)
            {
                printf("Nein");
                break;
            }
            if (i == n ) printf("Ja");
        }
        if (n <= 1) printf ("Nein");
    }
    return 1;

}

///Nachkommastellen einer Zahl in Binärsystem umwandeln
int Binary()
{
    printf("\n\n=======================================================================");
    printf("\nEPR Praktium 2 - Aufgabe 3: Umwandlung von Nachkommastellen\n"
                   "Dieser Programmteil liest eine Gleitkommazahl zwischen 0 und 1 ein"
                   "und wandelt die Nachkommastellen ins Binärsystem um");

    //für diesen Teil wird eine float benötigt
    float f=1.0, wert;
    int b=0, n=0;
    printf("\nGeben Sie eine Zahl zwischen 0 und 1 ein (0 für Abbruch): ");
    while (f>=1 || f<0) {
        scanf("%f",&f);
    }
    if (f==0) return 0;
    wert=f;

    //Maximale Anzahl der Nachkommastellen festlegen
    printf("\nGeben Sie die gewünschte Anzahl an Nachkommastellen ein: ");
    scanf("%d", &n);

    printf("Binärdarstellung von %f ist: ", f);
    printf("\nFor:\n0.");

    //Zähler für alle Schleifen
    int i = 0;
    //For Schleife
    for (i=0; i<n;i++)
    {
        f *= 2;
        b = (int) f;
        printf("%d", b);
        f-=b;
        //if((f -= b)==0) break; //Für Abbruch wenn keine weiteren Stellen !=0 folgen
    }

    f=wert;
    i=0;
    printf("\nWhile:\n0.");
    //While Schleife
    while (i<n) //Für Abbruch wenn keine weiteren Stellen !=0 folgen: && f != 0)
    {
        f*=2;
        b = (int) f;
        printf("%d", b);
        f -= b;
        i++;
    }

    f=wert;
    i=0;
    printf("\nDo-While:\n0.");
    //do-while schleife
    do
    {
        f*=2;
        b = (int) f;
        printf("%d", b);
        f -= b;
        i++;
    }while (i<n );//Für Abbruch wenn keine weiteren Stellen !=0 folgen & f!=0);
    return 1;

}

///Zahl in beliebiges System von 2-36 umwandeln
int AnySys()
{
    float f=0.0, wert;
    int b=0, n=0, c;
    printf("\nGeben Sie eine Zahl zwischen 0 und 1 ein (0 für Abbruch): ");
    scanf("%f",&f);
    if (f==0) return 0;
    wert=f;

    printf("\nGeben Sie an, auf welche Basis gewandelt werden soll [2-36]: ");
    scanf("%d", &b);

    //Maximale Anzahl der Nachkommastellen festlegen
    printf("\nGeben Sie die gewünschte Anzahl an Nachkommastellen ein: ");
    scanf("%d", &n);

    printf("darstellung von %f im %d-System ist: ", f, b);

    //wert=f=15.55;
    //b=2;
    //n=2;

    //Vor komma
    int i = 0;
    printf("\nVorkomma Umwandlung: ");
    while ((int)wert / b > 0) {
        printf("%d ",(int)wert%b);
        wert=(int)wert/b;
    }
    printf("%d ",(int)wert%b);

    //Nach Komma
    printf("\nNachkomma Umwandlung: ");
    wert= f-(int)f;

    for (i=0; i<n;i++)
    {
        wert *= b;
        c = (int) wert;
        printf("%d ", c);
        if((wert -= c)==0) break;
    }
    return 1;
}



int main()
{
    int run =1;
    while(run)
    {
        run = Primzahl();
    }
    run = 1;
    while(run)
    {
        run = Primzahlliste();
    }
    run =1;
    while(run)
    {
        run = Binary();
    }
    //AnySys();
}