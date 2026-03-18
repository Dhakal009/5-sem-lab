// WAP to implement binary search using divide and conquer approach.
#include <iostream>
using namespace std;

int binarySearch(int arr[], int left, int right, int key) {
    if (right >= left) {
        int mid = (left + right) / 2;

        if (arr[mid] == key) {
            return mid; 
        }
        if (arr[mid] > key) {
            return binarySearch(arr, left, mid - 1, key);
        }
        return binarySearch(arr, mid + 1, right, key);
    }
    return -1; 
}

void sortedArray(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int temp;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int main() {
    int n, key;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sortedArray(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Enter the key to search: ";
    cin >> key;
    int result = binarySearch(arr, 0, n - 1, key);
    if (result != -1) {
        cout << "Key found at index: " << result << endl;
    } else {
        cout << "Key not found in the array." << endl;
    }
    return 0;
}