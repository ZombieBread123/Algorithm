#include <iostream>
using namespace std;
int binarySearch(int arr[], int left, int right, int value) {
    int mid;
    if(left > right) return -1;
    else {
        mid = (left + right) / 2;
        if(arr[mid] == value) return mid;
        else if(arr[mid] > value) return binarySearch(arr, left, mid - 1, value);
        else return binarySearch(arr, mid + 1, right, value);
    }
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        int value;
        cin >> n >> value;
        int arr[n];
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << binarySearch(arr, 0, n - 1, value) << endl;
    }
}