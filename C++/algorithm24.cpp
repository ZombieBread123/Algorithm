#include <iostream>
using namespace std;
int merge(int arr[], int low, int mid, int high, long long &count){
    int i, j, k;
    int tmp[10000];
    for(i = low; i <= high; i++) tmp[i] = arr[i];
    i = k = low;
    j = mid + 1;
    while(i <= mid && j <= high) {
        if(tmp[i] <= tmp[j]) {
            arr[k++] = tmp[i++];
            count++;
        } else {
            arr[k++] = tmp[j++];
            count++;
        }
    }
    while(i <= mid) arr[k++] = tmp[i++];
    while(j <= high) arr[k++] = tmp[j++];
}
int mergeSort(int arr[], int low, int high, long long &count) {
    int mid = (low + high) / 2;
    if(low == high) return 0;
    mergeSort(arr, low, mid, count);
    mergeSort(arr, mid + 1, high, count);
    merge(arr, low, mid, high, count);
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int arr[n];
        for(int i = 0; i < n; i++) cin >> arr[i];
        long long count = 0;
        mergeSort(arr, 0, n - 1, count);
        cout << count << endl;
    }
}