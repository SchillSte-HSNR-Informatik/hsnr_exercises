#include <stdio.h>
/*strings, structs and call by reference
 * encoding and decoding strings by shifting the individual letters
 * by n steps each
 * decoding an old "secret message"
 * replacing ph with f
 * finding the output of a given program using a struct (paper-only)*/

///shift chars in input text forwards by n positions in the ascii table
void encode (char * text, int n){
    for (int i=0; text[i]!='\0';i++){
        *(text+i)+=n;
    }
}

///shift chars in input text backwards by n positions in the ascii table
void decode (char * text, int n){
    for (int i=0; *(text+i)!='\0';i++){
        *(text+i)-=n;
    }
}

///replace ph and Ph with f / F
void rechtschreibreform(char *text){
    int j=0;
    int i;
    for (i=0; *(text+i+j)!='\0';i++){
        //ersetzen
        if((text[i+j]=='p' || text[i+j]=='P') &&  text[i+j+1]=='h'){
            if (text[i+j]=='p') text[i] = 'f';
            else text[i]='F';
            j++;
        }
        //kopieren
        else{
            text[i] = text[i+j];
        }
    }
    text[i] = '\0';
}

int main() {
    int n=25;
    char text[] = "Hallo! Alle Studenten lieben Kerzenlicht.";
    printf("\n%s",text);
    encode(text,n);
    printf("\n%s",text);
    decode(text, n);
    printf("\n%s",text);


    char text2[] = "JDOOLD HVW RPQLV GLYLVD LQ SDUWHV WUHV";
    for (int i=1; i<25; i++){
        decode(text2, 1);
        printf("\n%s",text2);
    }
    //PLAINTEXT GALLIA EST OMNIS DIVISA IN PARTES TRES
    //warum Lateinkram hier? Ist kein Pflichtfach...

    char text3[] = "Photographie";
    printf("\n%s", text3);
    rechtschreibreform(text3);
    printf("\n%s", text3);
}