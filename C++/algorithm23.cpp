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
//mergesort iterative
int mergeSort(int arr[], int n, long long &count) {
    int size = 1;
    while(size < n) {
        for(int i = 0; i < n; i += 2 * size) {
            int low = i;
            int mid = low + size - 1;
            int high = min(i + 2 * size - 1, n - 1);
            if(mid >= n - 1) break;
            merge(arr, low, mid, high, count);
        }
        size *= 2;
    }
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
        mergeSort(arr, n, count);\
        cout << count << endl;
    }
}