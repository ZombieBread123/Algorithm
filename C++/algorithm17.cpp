#include <iostream>
using namespace std;
int kadane(int arr[], int n) {
    int max_so_far = 0;
    int max_ending_here = 0;
    int start_index = 0;
    int temp_start_index = 0;
    int end_index = -1;
    for (int i = 0; i < n; i++) {
        max_ending_here += arr[i];
        if (max_ending_here < 0) {
            max_ending_here = 0;
            if(arr[i + 1] == 0) {
                temp_start_index = i + 2;
            } else {
                temp_start_index = i + 1;
            }
        }
        if (max_so_far < max_ending_here || (max_so_far == max_ending_here && (end_index - start_index > i - temp_start_index) && start_index > temp_start_index)) {
            max_so_far = max_ending_here;
            start_index = temp_start_index;
            end_index = i;
        }
    }
    if(max_so_far <= 0) {
        max_so_far = 0;
        start_index = -1;
        end_index = -1;
    }
    cout << max_so_far << " " << start_index << " " << end_index << endl;
    return 0;
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int arr[n];
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int k = sizeof(arr) / sizeof(arr[0]);
        kadane(arr, k); 
    }
    return 0;
}