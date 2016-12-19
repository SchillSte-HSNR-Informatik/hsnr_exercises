#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*Structs and dynamic memory allocation (malloc/realloc)
 * declaring a struct
 * defining a variable of this struct
 * declaring the struct with type name
 * string-table using char pointers,
 * finding output of given program code (code copied here)*/


///filling the declaration, declaration with type
///and definition of a related variable in one go
struct klausur { //providing a name for the struct is not necessary
    struct{
        int tag;
        int monat;
        int jahr;
    }tagDerKlausur;
    int matrikelnummer;
    int note;
    char *nachname;
    char *fach;
} var; //Variable can be created by tagging it at the end of the struct declaration

void print_tage(char *tage_ptr[], int n)
{
    int i;
    for (i = 0; i<n; i++) {
        printf("%s\n", tage_ptr[i]);
    }
    tage_ptr[2][4] = 'z';
}
void main()
{
    char **tage;
    tage = (char**) calloc(3,sizeof(char*));
    tage[0] = (char*) malloc((strlen("Montag")+1) * sizeof(char));
    strcpy(tage[0], "Montag");
    tage[1] = (char*) calloc(strlen("Dienstag")+1, sizeof(char));
    strcpy(tage[1], "Dienstag");
    tage[2] = (char*) calloc(1, sizeof("Mittwoch"));
    strcpy(tage[2], "Mittwoch");
    printf("%s\n", tage[1]); //prints "Dienstag"
    printf("%s\n", *(tage+1)); //prints "Dienstag" too
    printf("%s\n", *(tage+2)+4); //prints Mittwoch from it's 5th letter - "woch"
    print_tage(tage,3); //prints "Montag\nDienstag\nMittwoch"
    printf("%s\n", tage[2]);//prints "Mittzoch", as the previously executed print_tage replaced 'w' with 'z'

    //initialize "klausur" struct variable
    var.fach="EPR";
    var.matrikelnummer=12345;
    var.nachname="Mustermann";
    var.note=1;
    var.tagDerKlausur.jahr=1999;
    var.tagDerKlausur.monat=3;
    var.tagDerKlausur.tag=13;

    //some test output
    printf("\n%s",var.fach);
    printf("\n%s",var.nachname);
    printf("\n%d",var.note);
}