// WAP to perform sequential search using iterative method.

#include <iostream>
using namespace std;
int main() {
    int n, key;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the key to search: ";
    cin >> key;

    bool found = false;
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            found = true;
            cout << "Key found at index: " << i << endl;
            break;
        }
    }

    if (!found) {
        cout << "Key not found in the array." << endl;
    }

    return 0;
}
