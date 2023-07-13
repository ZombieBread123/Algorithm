#include <iostream>

using namespace std;
//백준 11047번 문제
int main() {
    int n, k;
    cin >> n >> k;
    int arr[n];

    for (int i = 0; i < n; i++) 
        cin >> arr[i];
    
    int cnt = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (k >= arr[i]) {
            cnt += k / arr[i];
            k %= arr[i];
        }
    }
    cout << cnt;

    return 0;
}