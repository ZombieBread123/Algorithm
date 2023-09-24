#include <iostream>
using namespace std;
int removeTrailingZeros(int n) {
    while (n % 10 == 0) {
        n /= 10;
    }
    return n % 10000;
}
int factorialTail(int n, int acc) {
    if (n <= 1) {
        return acc;
    } else {
        return factorialTail(n - 1, removeTrailingZeros(n * acc));
    }
}
int factorial(int n) {
    return factorialTail(n, 1);
}
int main() {
    int numTestCases;
    cin >> numTestCases;
    for (int i = 0; i < numTestCases; i++) {
        int n;
        cin >> n;
        cout << factorial(n) % 1000 << endl;
    }
}