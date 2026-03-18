// WAP to find the minimum and maximum elements in a list using max-min finding algorithm.
#include <iostream>
using namespace std;
void findMinMax(int arr[], int n, int &min, int &max) {
    if (n == 1) {
        min = max = arr[0];
        return;
    }
    if (arr[0] < arr[1]) {
        min = arr[0];
        max = arr[1];
    } else {
        min = arr[1];
        max = arr[0];
    }
    for (int i = 2; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        } else if (arr[i] > max) {
            max = arr[i];
        }
    }
}
int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int min, max;
    findMinMax(arr, n, min, max);
    cout << "Minimum element: " << min << endl;
    cout << "Maximum element: " << max << endl;
    return 0;
}