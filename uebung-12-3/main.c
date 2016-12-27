#include <stdio.h>
#define _USE_MATH_DEFINES // fuer die Verwendung von #define aus math.h, wie M_PI
#include <math.h>
/* numerische Integration
 * fuer 3 vorgegebene Funktionen von x*/

double integral(double (*f)(double), double a, double b);
double linear(double x);
double quadratic(double x);
double sinus(double x);
double integral_precision( double (*f)(double), double a, double b);

int main() {
    int selector = 0, running = 1;
    double (*function_ptr)(double);
    printf("Integralberechnung\n");
    printf("==================\n");
    while (running){
        printf("Integral welcher Funktion? \n");
        printf("(1) f(x) = x\n"
                       "(2) f(x) = x^2 + 1.5\n"
                       "(3) f(x) = sin (x)\n"
                       "Auswahl: ");
        scanf("%d", &selector);
        running = 0;
        switch(selector){
            case 1:
                function_ptr = linear;
                break;
            case 2:
                function_ptr = quadratic;
                break;
            case 3:
                function_ptr = sinus;
                break;
            default:
                printf("ungueltige Eingabe!\n");
                running = 1;
                break;
        }
    }

    printf("Fuer welchen Bereich soll das Integral berechnet werden?\n");
    printf("Start: ");
    double a=0, b=0;
    scanf("%lef", &a);
    printf("Ende: ");
    scanf("%lf", &b);

    double result = integral(function_ptr, a, b);
    printf("Das Integral der Funktion ist: %lf\n", result);

    result = integral_precision(function_ptr, a, b);
    printf("Das genauere Integral der Funktion ist: %lf\n", result);
    return 0;
}

/// schaetzt Integral unter Kurve als Trapezflaeche ab
double integral (double (*f)(double), double a, double b){
    return (f(a) + f(b)) * (b - a) / 2;
}

/// schaetzt Integral als Summe von n Trapezflaechen unter der Kurve ab
double integral_precision (double (*f)(double), double a, double b){
    printf("In wieviele Teilstuecke soll das Interval zerlegt werden? ");
    double n=0;
    scanf("%lf",&n);
    n = (int) n;

    double result = 0;
    for(int i = 1; i <= n; i++){
        result += (f(a+(i-1)*(b-a)/n) + f(a+i*(b-a)/n)) / 2;
    }
    return result*(b-a)/n;
}

double linear (double x){
    return x;
}

double quadratic (double x){
    return (x*x + 1.5);
}

///sinus funktion aus math.h?
double sinus (double x){
    return sin(x);
}