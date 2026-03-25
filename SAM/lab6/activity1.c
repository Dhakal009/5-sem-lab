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
#include <stdlib.h>

typedef struct {
    int interarrival;
    int arrival;
    int service;
    int start;
    int completion;
    int waiting;
    int turnaround;
    int idle;
} Customer;

int main() {
    int i;
    int n;
    float total_wait = 0, total_turnaround = 0, total_service = 0;
    int total_idle = 0;

    printf("Enter number of customers: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number of customers.\n");
        return 1;
    }

    Customer *customers = (Customer *)malloc(n * sizeof(Customer));
    if (customers == NULL) {
        printf("Memory allocation failed.\n");k
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("\nCustomer %d\n", i + 1);
        printf("Time since last arrival: ");
        if (scanf("%d", &customers[i].interarrival) != 1 || customers[i].interarrival < 0) {
            printf("Invalid interarrival time.\n");
            free(customers);
            return 1;
        }

        printf("Service time: ");
        if (scanf("%d", &customers[i].service) != 1 || customers[i].service <= 0) {
            printf("Invalid service time.\n");
            free(customers);
            return 1;
        }
    }

    customers[0].arrival = customers[0].interarrival;
    customers[0].start = customers[0].arrival;
    customers[0].completion = customers[0].start + customers[0].service;
    customers[0].waiting = 0;
    customers[0].turnaround = customers[0].service;
    customers[0].idle = customers[0].arrival;

    total_idle += customers[0].idle;

    for (i = 1; i < n; i++) {
        customers[i].arrival = customers[i - 1].arrival + customers[i].interarrival;

        if (customers[i].arrival > customers[i - 1].completion) {
            customers[i].start = customers[i].arrival;
            customers[i].idle = customers[i].arrival - customers[i - 1].completion;
        } else {
            customers[i].start = customers[i - 1].completion;
            customers[i].idle = 0;
        }

        customers[i].completion = customers[i].start + customers[i].service;
        customers[i].waiting = customers[i].start - customers[i].arrival;
        customers[i].turnaround = customers[i].completion - customers[i].arrival;

        total_idle += customers[i].idle;
    }

    for (i = 0; i < n; i++) {
        total_wait += customers[i].waiting;
        total_turnaround += customers[i].turnaround;
        total_service += customers[i].service;
    }

    float avg_wait = total_wait / n;
    float avg_turnaround = total_turnaround / n;
    float avg_service = total_service / n;

    int total_time = customers[n - 1].completion;
    float utilization = ((float)total_service / total_time) * 100;
    float idle_percent = ((float)total_idle / total_time) * 100;

    printf("\nCust\tIAT\tAT\tST\tStart\tCT\tWT\tTAT\tIdle\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               i + 1,
               customers[i].interarrival,
               customers[i].arrival,
               customers[i].service,
               customers[i].start,
               customers[i].completion,
               customers[i].waiting,
               customers[i].turnaround,
               customers[i].idle);
    }

    printf("\n--- Results ---\n");
    printf("Average Waiting Time = %.2f\n", avg_wait);
    printf("Average Time in System = %.2f\n", avg_turnaround);
    printf("Average Service Time = %.2f\n", avg_service);
    printf("Server Utilization = %.2f%%\n", utilization);
    printf("Total Idle Time = %d\n", total_idle);
    printf("Idle Time Percentage = %.2f%%\n", idle_percent);

    free(customers);

    return 0;
}

