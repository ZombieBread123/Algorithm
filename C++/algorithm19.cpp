#include <iostream>
using namespace std;
#define MAX(a, b) ((a) > (b) ? (a) : (b))
int max(int arr[], int left, int right) {
    int half;
    if(left == right) {
        return arr[left];
    } else {
        half = (left+right) / 2;
        return MAX(max(arr, left, half), max(arr, half+1, right));
    }
}
int main()
{
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int arr[n];
        for(int i = 0; i < n; i++) cin >> arr[i];
        cout << max(arr, 0, n - 1) << endl;
    }
    return 0;
}