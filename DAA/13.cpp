// WAP to perform fractional knapsack problem using greedy approach.
#include <iostream>
#include <algorithm>
using namespace std;
struct Item {
    int weight;
    int value;
};
bool compare(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(Item arr[], int n, int capacity) {
    sort(arr, arr + n, compare);
    double totalValue = 0.0;
    for (int i = 0; i < n; i++) {   
        if (arr[i].weight <= capacity) {
            totalValue += arr[i].value;
            capacity -= arr[i].weight;
        } else {
            totalValue += arr[i].value * ((double)capacity / arr[i].weight);
            break;
        }
    }
    return totalValue;
}
int main() {
    int n, capacity;
    cout << "Enter the number of items: ";
    cin >> n;
    Item arr[n];
    
    for (int i = 0; i < n; i++) {
        cout << "Enter weight and value of " << i+1<< " item: ";
        cin >> arr[i].weight >> arr[i].value;
    }
    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;    
    cout << "Maximum value that can be obtained: " << fractionalKnapsack(arr, n, capacity) << endl;
    return 0;
}