// WAP to find additive inverse of a number in Zn.
#include <stdio.h>

int main() {
    int a,n;
    printf("Enter a number: ");
    scanf("%d", &a);
    printf("Enter n: ");
    scanf("%d", &n);
    
    int additive_inverse = (n - (a % n)) % n;
    
    printf("Additive inverse of %d in Z%d is: %d\n", a, n, additive_inverse);
    
    return 0;
}