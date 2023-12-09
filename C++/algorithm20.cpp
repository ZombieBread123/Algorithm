#include <iostream>
using namespace std;
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
        int maxLength = 1;
        int currentLength = 1;
        int firstIndex = 0;
        for(int i = 1; i < n; i++) {
            if(arr[firstIndex] <= arr[i]) {
                currentLength++;
            } else {
                currentLength = 1;
                firstIndex = i;
            }
            maxLength = max(maxLength, currentLength);
        }
        cout << maxLength << endl;
    }
}