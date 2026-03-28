/*
Activity2: Modify the program of activity 1 and calculate the 
        ◦ average waiting time, 
        ◦  minimum wait time, 
        ◦ maximum wait time, 
        ◦ average number of customer in the system
Algorithm
1. Create one structure Customer with following 
    • int arrivalTime;
    • int serviceTime;
    • int startTime;
    • int endTime;'
2. Generate Customer, Arrival Time Service Time and stored them in a structure 
3. Calculate the  Service Begin, Service End Times of each customer 
4. Generate the the statisctics in tabular form with following heading 
    • Customer No
    • Inter Arrival
    • Arrival Time 
    • Ser. Time: 
    • Ser. Begin: 
    • Service end 
    • T.spent 
    • Idle time
5. Print the following  Performance parameters of the queue 
    • Average Wait Time
    • Average Time Spent in System
    • Average Service time
    • Server Utilization
    • Total Idle Time and percentage 
*/


#include <stdio.h>

#define MAX_CUSTOMERS 20
#define INT_MAX 2147483647

typedef struct {
    int iat, at, st, start, ct, wt, tat, idle;
} Customer;

int main() {
    int n;
    double total_wait = 0, total_tat = 0, total_service = 0;
    int total_idle = 0, prev_arrival = 0, prev_completion = 0;

    int min_wt = INT_MAX, max_wt = 0;

    Customer customers[MAX_CUSTOMERS];

    printf("Enter number of customers (1-%d): ", MAX_CUSTOMERS);
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nCustomer %d\n", i + 1);

        printf("Interarrival time: ");
        scanf("%d", &customers[i].iat);

        printf("Service time: ");
        scanf("%d", &customers[i].st);

        customers[i].at = prev_arrival + customers[i].iat;

        customers[i].start = (customers[i].at > prev_completion) 
                             ? customers[i].at 
                             : prev_completion;

        customers[i].idle = customers[i].start - prev_completion;
        customers[i].ct = customers[i].start + customers[i].st;

        customers[i].wt = customers[i].start - customers[i].at;
        customers[i].tat = customers[i].ct - customers[i].at;

        // Update totals
        total_wait += customers[i].wt;
        total_tat += customers[i].tat;
        total_service += customers[i].st;
        total_idle += customers[i].idle;

        // Min & Max waiting time
        if (customers[i].wt < min_wt) min_wt = customers[i].wt;
        if (customers[i].wt > max_wt) max_wt = customers[i].wt;

        prev_arrival = customers[i].at;
        prev_completion = customers[i].ct;
    }

    double avg_wait = total_wait / n;
    double avg_tat = total_tat / n;
    double avg_service = total_service / n;

    int total_time = prev_completion;

    double utilization = (total_service / total_time) * 100.0;
    double idle_percent = ((double)total_idle / total_time) * 100.0;

    // Average number of customers in system
    double avg_customers_system = total_tat / total_time;

    printf("\nCust\tIAT\tAT\tST\tStart\tCT\tWT\tTAT\tIdle\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
            i + 1,
            customers[i].iat,
            customers[i].at,
            customers[i].st,
            customers[i].start,
            customers[i].ct,
            customers[i].wt,
            customers[i].tat,
            customers[i].idle);
    }

    printf("\n--- Results ---\n");
    printf("Average Waiting Time = %.2lf\n", avg_wait);
    printf("Minimum Waiting Time = %d\n", min_wt);
    printf("Maximum Waiting Time = %d\n", max_wt);
    printf("Average Customers in System = %.2lf\n", avg_customers_system);
    printf("Average Time in System = %.2lf\n", avg_tat);
    printf("Average Service Time = %.2lf\n", avg_service);
    printf("Server Utilization = %.2lf%%\n", utilization);
    printf("Total Idle Time = %d\n", total_idle);
    printf("Idle Time Percentage = %.2lf%%\n", idle_percent);

    return 0;
}


