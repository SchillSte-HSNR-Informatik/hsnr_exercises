/* Berechnung von Binomialkoeffizienten durch Rekursion
 * verwendete Rechenvorschrift:
 *    n      n-1   n-1
 *  (   ) = (   )+(   )
 *    k      k-1    k
 *
 *  mit den Ergebnis eins für die Fälle n = k und k = 0
 *
 *    alternative Definition des Binomialkoeffizienten mit Fakultaet:
 *    n          n!
 *  (   ) = -----------
 *    k     k! * (n-k)!    */

#include <stdio.h>

int binomial (int n, int k){
    if (k==0 || n == k) return 1;
    else return (binomial (n-1, k-1) + binomial(n-1, k));
}

int main() {
    int n=6;
    int k=2;
    printf("Binomialkoeffizient %d ueber %d ist: %d\n", n, k, binomial(n,k));
    return 0;
}