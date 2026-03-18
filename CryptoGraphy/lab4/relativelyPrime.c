// WAP to test wheather two numbers are relatively prime or not using Extended Euclidean algorithm.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int extended_gcd(int n, int a, int *x) {
    int r1 = n, r2 = a;
    int t1 = 0, t2 = 1; 
    int q, r, t;
   
    while (r2 != 0) {
        q = r1 / r2;
        r = r1 - q * r2;
        t = t1 - q * t2;
        r1 = r2;
        r2 = r;
        t1 = t2;
        t2 = t;
    }
    *x = t1;
    return r1;
}

int main() {
    int n, a, x, y, gcd;

    printf("Enter the value of first number: ");
    scanf("%d", &n);

    printf("Enter the value of second number: ");
    scanf("%d", &a);

    gcd = extended_gcd(n, a, &x);

    if (gcd != 1) {
        printf("The %d and %d are not relatively prime\n", a, n);
    } else {
        printf("The %d and %d are relatively prime\n", a, n);
    }
    return 0;
}