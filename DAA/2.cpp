// WAP to find the nth term of Fibonacci sequence using iterative method.

#include<iostream>
using namespace std;
int main() {
    int n, a = 0, b = 1;
    cout<<"Enter the number of terms: ";
    cin >> n;
    for (int i = 1; i < n; i++) {
        int temp = a + b;
        a = b;
        b = temp;
    }
    cout <<"The "<< n <<"th term of the Fibonacci sequence is: "<< a << endl;
    return 0;
}


