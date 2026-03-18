/*
    Activity 2: FInding Cycle Length Modify the above program (activity 1) and find the cycle length. once you identify there is present of same random number as given in seed, you have to terminate your program.

    eg. In activity 1 if you try to generate 20 random numbers, the numbers repaat after 15 uniques numbers (2,21,6,26,20,28,7,4,8,13,27,29,16,23,24,2...). In this case your program should stop generating repeated random numbers
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
        if (R[i+1] == R[0])
        {
            printf("\nCycle detected at index %d with value %d. Terminating.\n", i, R[i]);
            break;
        }
        
    }
    printf("\n");
    return 0;   
}
