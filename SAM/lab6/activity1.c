/*
    Scenario:  
    • Grocery shop with Single Checkout counter   
    • Customer arrival in 1 to 8 min Gap with equal probability
    • Each customer takes 1 to 6 min of service time with equal probability 
    Activity1: Create a simulation table for given scenario for 20 customers. Also Calculate the 
        ◦ Average Wait Time
        ◦ Average Time Spent in System by customer 
        ◦ Average Service time
        ◦ Server Utilization
        ◦ Total Idle Time and percentage
*/

#include <stdio.h>

#define MAX_CUSTOMERS 20

typedef struct {
    int iat;
    int at;
    int st;
    int start;
    int ct;
    int wt;
    int tat;
    int idle;
} Customer;

int main() {
    int n;
    double total_wait = 0, total_tat = 0, total_service = 0;
    int total_idle = 0, prev_arrival = 0, prev_completion = 0;
    Customer customers[MAX_CUSTOMERS];

    printf("Enter number of customers (1-%d): ", MAX_CUSTOMERS);
    if (scanf("%d", &n) != 1 || n <= 0 || n > MAX_CUSTOMERS) {
        printf("Invalid number of customers.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("\nCustomer %d\n", i + 1);
        printf("Time since last arrival: ");
        if (scanf("%d", &customers[i].iat) != 1 || customers[i].iat < 0) {
            printf("Invalid interarrival time.\n");
            return 1;
        }

        printf("Service time: ");
        scanf("%d", &customers[i].st) ;

        customers[i].at = prev_arrival + customers[i].iat;
        customers[i].start = (customers[i].at > prev_completion) ? customers[i].at : prev_completion;
        customers[i].idle = customers[i].start - prev_completion;
        customers[i].ct = customers[i].start + customers[i].st;
        customers[i].wt = customers[i].start - customers[i].at;
        customers[i].tat = customers[i].ct - customers[i].at;

        total_wait += customers[i].wt;
        total_tat += customers[i].tat;
        total_service += customers[i].st;
        total_idle += customers[i].idle;

        prev_arrival = customers[i].at;
        prev_completion = customers[i].ct;
    }

    double avg_wait = total_wait / n;
    double avg_tat = total_tat / n;
    double avg_service = total_service / n;

    int total_time = prev_completion;
    double utilization = (total_service / total_time) * 100.0;
    double idle_percent = ((double)total_idle / total_time) * 100.0;

    printf("\nCust\tIAT\tAT\tST\tStart\tCT\tWT\tTAT\tIdle\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
i + 1,customers[i].iat,customers[i].at,customers[i].st,customers[i].start,customers[i].ct,customers[i].wt,customers[i].tat,customers[i].idle);
    }

    printf("\n--- Results ---\n");
    printf("Average Waiting Time = %.2lf\n", avg_wait);
    printf("Average Time in System = %.2lf\n", avg_tat);
    printf("Average Service Time = %.2lf\n", avg_service);
    printf("Server Utilization = %.2lf%%\n", utilization);
    printf("Total Idle Time = %d\n", total_idle);
    printf("Idle Time Percentage = %.2lf%%\n", idle_percent);

    return 0;
}

