#include <iostream>
#include <algorithm>

using namespace std;
//백준 11399번 문제
bool desc(int a, int b) {
    return a < b;
}

int main() {
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++) 
        cin >> arr[i];
    
    sort(arr, arr + n, desc);

    int cnt = 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cnt += arr[i];
        sum += cnt;
    }
    cout << sum;

    return 0;
}