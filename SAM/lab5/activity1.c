/*
        Activity 1: Implementation Coke vs. Pepsi Example for Markov Process
    • Given that a person’s last cola purchase was Coke, there is a 90% chance that his next cola purchase will also be Coke.
    • If a person’s last cola purchase was Pepsi, there is an 80% chance that his next cola purchase will also be Pepsi.
            T  =[ 0.9  0.1 
	       0.2  0.8 ]
            For the above answer the following questions
    1. Given that a person is currently a Pepsi purchaser, what is the probability that he will purchase Coke two purchases from now?
                  T2=    [0.83 0.17
                          0.34  0.66]
        Ans: 0.34
    2.  Given that a person is currently a Coke purchaser,  what is the probability that he will purchase Pepsi three purchases from now?
             Ans:  .219 
    3. Suppose 60% of all people now drink Coke, and 40% drink Pepsi . What fraction of people will be drinking Coke after three purchase from now?
               P0=[0.6, 0.4]
               Pn=P0*T^n
               P3= P0*T^3   =(0.6438,0.3562) 

 STEP 1 : Take 2 by 2 matrix say T
 Step2 : Ask for after how many times we need a prob of choice (say N)
 STEP3: Multiply the transition matrix upto N times (T^N)
 STE4: Pick the required index to get answer
 step 5: display the answer
*/




#include <stdio.h>

void multiply(float a[2][2], float b[2][2], float r[2][2]) {
    r[0][0] = a[0][0] * b[0][0] + a[0][1] * b[1][0];
    r[0][1] = a[0][0] * b[0][1] + a[0][1] * b[1][1];
    r[1][0] = a[1][0] * b[0][0] + a[1][1] * b[1][0];
    r[1][1] = a[1][0] * b[0][1] + a[1][1] * b[1][1];
}

void multiplyVector(float p[2], float t[2][2], float r[2]) {
    r[0] = p[0] * t[0][0] + p[1] * t[1][0];
    r[1] = p[0] * t[0][1] + p[1] * t[1][1];
}

int main() {
    float t[2][2], t2[2][2], t3[2][2], p0[2], p3[2];
    int row, col;

    printf("\nEnter the 2x2 transition matrix:\n");
    for (row = 0; row < 2; row++) {
        for (col = 0; col < 2; col++) {
            scanf("%f", &t[row][col]);
        }
    }

    multiply(t, t, t2);     // T^2
    multiply(t2, t, t3);    // T^3

    printf("\nQ1: Probability that a Pepsi purchaser will buy Coke after 2 purchases.\n");
    printf("T2 Matrix:\n%.4f %.4f\n%.4f %.4f\n", t2[0][0], t2[0][1], t2[1][0], t2[1][1]);
    printf("Probability (Pepsi -> Coke in 2 steps): %.4f\n", t2[1][0]);

    printf("\nQ2: Probability that a Coke purchaser will buy Pepsi after 3 purchases.\n");
    printf("T3 Matrix:\n%.4f %.4f\n%.4f %.4f\n", t3[0][0], t3[0][1], t3[1][0], t3[1][1]);
    printf("Probability (Coke -> Pepsi in 3 steps): %.4f\n", t3[0][1]);

    printf("\nQ3: Enter initial state distribution (Coke, Pepsi): ");
    scanf("%f %f", &p0[0], &p0[1]);

    multiplyVector(p0, t3, p3);
    printf("After 3 steps (Coke, Pepsi): (%.4f, %.4f)\n", p3[0], p3[1]);

    return 0;
}