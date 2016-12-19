#include <stdio.h>
//^fuer strcmp zum beenden des programms verwendet. S 491 im skript.
//etwas weiter hinten werden auch  "isalpha(char)" und "tolower(char)" aus der ctype.h erwaehnt
//statt die hier zu verwenden bleibt diese Loesung auf manuelles char-schubsen beschraenkt.

///gibt zurueck, ob zeichenkette ein palindrom ist (rueckwaerts und vorwaerts gelesen gleich)
int palindrom(char in[]){
    int n = 0;
    //*in == in[0]
    while (*(in+n) != '\0'){
        n++;
    }
    //pruefung bis zur haelfte bzw mitte reicht
    for (int i = 0; i<(n/2); i++){
        if (in[i]!=in[n-i-1]) return 0;
    }
    return 1;
}

///entfernt sonderzeichen aus zeichenkette
void removeNonLetters(char in[]){
    int i = 0;
    int j = 0;
    char out[100];
    while (in[i] != '\0'){
        if (in[i] >= 'a' && in[i] <= 'z' || in[i] >= 'A' && in[i]<='Z'){
            in[j] = in[i];
            j++;
        }
        i++;
    }
    in[j]='\0';
}

///wandelt alle grossbuchstaben einer zeichenkette in kleinbuchstaben um
void toLower(char in[]){
    int i = 0;
    while (in[i] != '\0'){
        if (in[i] >= 'A' && in[i]<='Z'){
            in[i] += ('a'-'A');
        }
        i++;
    }
}

int main() {
    int n=0;
    char test[30];
    char *testdaten[] = { "Ha/n/nah", "La-ger-regal", "O%t/to", "(Reit-)tier",
                          "Reliefpfeiler", "Ren--tner", "R!o!t)or", "st--ets",
                          "nein" "Hall67o", "Lastwa$gen" };
    while(n<10){
        int i;
        for (i=0; testdaten[n][i]!='\0';i++){
            test[i]=testdaten[n][i];
        }
        test[i]='\0'; //^packt unveränderlichen, de-referenzierten Pointer-Inhalt in char array, für Verwendung in removeNonLetters + toLower

        printf("\nOriginal: %s",test);
        printf("\n");
        if (palindrom(test)) printf("Palindrom: ");
        else printf("kein Palindrom: ");
        printf("%s",test);

        removeNonLetters(test);
        printf("\nNach removeNonLetters: %s", test);
        printf("\n");
        if (palindrom(test)) printf("Palindrom: ");
        else printf("kein Palindrom: ");
        printf("%s",test);

        toLower(test);
        printf("\nNach toLower: %s", test);
        printf("\n");
        if (palindrom(test)) printf("Palindrom: ");
        else printf("kein Palindrom: ");
        printf("%s\n**********************************************************\n\n",test);
        n++;
    }
    return 0;
}
