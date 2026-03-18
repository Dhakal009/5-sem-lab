/*
    Activity 1: Use Linear Congruential Method (LCM) to generate random numbers. Write C Program tp generate random numbers using LCM and calculate the mean and variance of the generated random numbers. 

    Your program should ask for user input like how many digits, how many random numbers, initial value (R0),constant values: a and c
    Then calculate the Random number using Ri+1 = (a*Ri + c) mod m, where m should be determine based on the number of digits

    Use: a = 9, c = 3, m = 31, R0 = 2

    ans: 2,21,6,26,20,28,7,4,8
    
*/

#include <stdio.h>
#include <math.h>
int main(){
    int R[100];
    int a,c,m,n;
    int i=0;
    printf("Enter value of R0: ");
    scanf("%d",&R[0]);
    printf("Enter value of multiplier a: ");
    scanf("%d",&a);
    printf("Enter value of increment c: ");
    scanf("%d",&c);
    printf("Enter value of modulus m: ");
    scanf("%d",&m);
    printf("Enter number of random numbers to generate: ");
    scanf("%d",&n);
    while(i<n){
        R[i+1] = (a*R[i] + c) % m;
        i++;
    }
    printf("Generated random numbers: ");
    for(i=0;i<n;i++){
        printf("%d ",R[i]);
    }
    printf("\n");
    return 0;   
}