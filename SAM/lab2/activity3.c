/*
    Activity 3: Apply all LCM(Additive, mixed or multiplicative) based on the input values of a and c(determine the type and generate the random numbers based on that). In this case you can provide a choice to user which method they want to choose. Based on the choice you should apply the respective formulas.
*/

#include<stdio.h>

int main()
{
    int R[100],a=0,c=0,m,i=0,n=0;
    printf("\nEnter the value of R[0]:");
    scanf("%d",&R[0]);
    printf("Enter the value of multiplier 'a' :");
    scanf("%d",&a);
    printf("Enter the value of increment 'c' :");
    scanf("%d",&c);
    printf("Enter the value of modulus 'm':");
    scanf("%d",&m);
    printf("Enter the number of random numbers to generate:");
    scanf("%d",&n);
    

    if(a==0 && c==0) {
        printf("\nInvalid input.\n");
        return 1;
    }

    if(a==0)
        printf("\nAdditive LCG\n");
    else if(c==0)
        printf("\nMultiplicative LCG\n");
    else
        printf("\nMixed LCG\n");

    for(i=1;i<=n;i++)
    {
        R[i] = (a * R[i-1] + c) % m;
    }
    
    printf("\nThe generated random numbers are:\n");
    for(i=0;i<=n;i++)
    {
        printf("%d ",R[i]);
        if(i<n && R[i+1]==R[0])
        {
            printf("\nCycle length is: %d\n",i);
            break;
        }
    }
    printf("\n");
    return 0;
}


