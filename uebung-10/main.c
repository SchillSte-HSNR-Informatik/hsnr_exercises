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
struct klausur{ //providing a name for the struct is not necessary
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

void changeName(struct klausur *var) {
    char name[] = "narf";
    (*var).nachname =malloc(sizeof(char) * (strlen(name) + 1));
    strncpy((*var).nachname, name, 5);
    //var->nachname = malloc(sizeof(char) * (strlen(name) + 1));
    //strncpy(var->nachname, name, strlen(name)+1);
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
    printf("%c\n", *(*(tage+2)+4)+2); //prints the 5th letter of the 3rd entry of tage, increased by 2: Mittwoch - w+2 -> y
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
    printf("Tag.Monat.Jahr: %d.%d.%d\n",var.tagDerKlausur.tag,var.tagDerKlausur.monat, var.tagDerKlausur.jahr);


    struct klausur var2 = {{1}, 2, 2, "derp", "herp"};
    printf("Tag.Monat.Jahr: %d.%d.%d\n",var2.tagDerKlausur.tag,var2.tagDerKlausur.monat, var2.tagDerKlausur.jahr);
    printf("\n%s",var2.fach);
    printf("\n%s",var2.nachname);
    printf("\n%d",var2.note);

    changeName(&var2);
    printf("\n%s",var2.nachname);
    (&(*(&var2)))->nachname = strdup("herp");
    printf("\n%s",var2.nachname);

}