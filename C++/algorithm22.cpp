#include <iostream>
using namespace std;
//quick sort Haore partition
int hoarePartition(int arr[], int low, int high, long long &comp, long long &swap) {
    int i = low - 1;
    int j = high + 1;
    int pivot = arr[low];
    while(true) {
        do {
            i++;
            comp++;
        } while(arr[i] < pivot);
        do {
            j--;
            comp++;
        } while(arr[j] > pivot);
        if(i < j) {
            std::swap(arr[i], arr[j]);
            swap++;
        }
        else return j;
    }
}
//quick sort Lomuto partition
int lumotoPartition(int arr[], int low, int high, long long &comp, long long &swap) {
    int pivot = arr[low];
    int j = low;
    for(int i = low + 1; i <= high; i++) {
        comp++;
        if(arr[i] < pivot) {
            j++;
            std::swap(arr[i], arr[j]);
            swap++;
        }
    }
    int pivotPos = j;
    std::swap(arr[pivotPos], arr[low]);
    swap++;
    return pivotPos;
}
int hoareQuicksort(int arr[], int low, int high, long long &comp, long long &swap) {
    if(low >= high) return 0;
    int p = hoarePartition(arr, low, high, comp, swap);
    hoareQuicksort(arr, low, p, comp, swap);
    hoareQuicksort(arr, p + 1, high, comp, swap);
}
int lumotoQuicksort(int arr[], int low, int high, long long &comp, long long &swap) {
    if(low >= high) return 0;
    int p = lumotoPartition(arr, low, high, comp, swap);
    lumotoQuicksort(arr, low, p - 1, comp, swap);
    lumotoQuicksort(arr, p + 1, high, comp, swap);
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int hoareArr[n];
        int lumotoArr[n];
        for(int i = 0; i < n; i++)  {
            cin >> hoareArr[i];
            lumotoArr[i] = hoareArr[i];
        }
        long long hoareComp = 0, hoareSwap = 0;
        long long lumotoComp = 0, lumotoSwap = 0;
        hoareQuicksort(hoareArr, 0, n - 1, hoareComp, hoareSwap);
        lumotoQuicksort(lumotoArr, 0, n - 1, lumotoComp, lumotoSwap);
        cout << hoareSwap << " " << lumotoSwap << " " << hoareComp << " " << lumotoComp << endl;
    }
}