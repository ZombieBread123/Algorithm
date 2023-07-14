#include <iostream>

using namespace std;
//백준 9095번 문제
int main() {
    int t, n;
    cin >> t;
    int arr[11] = { 0, 1, 2, 4, };
    for (int i = 4; i < 11; i++)
        arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
    for (int i = 0; i < t; i++) {
        cin >> n;
        cout << arr[n] << endl;
    }
    return 0;
}