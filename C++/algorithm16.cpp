#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool getNextPermutation(string& str) {
    int n = str.length();
    int i = n - 2;
    while (i >= 0 && str[i] >= str[i + 1]) {
        i--;
    }
    if (i < 0) {
        return false;
    }
    int j = n - 1;
    while (str[j] <= str[i]) {
        j--;
    }
    swap(str[i], str[j]);
    reverse(str.begin() + i + 1, str.end());
    return true;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string str;
        cin >> str;
        if (getNextPermutation(str)) {
            cout << str << endl;
        } else {
            sort(str.begin(), str.end());
            cout << str << endl;
        }
    }
    return 0;
}
