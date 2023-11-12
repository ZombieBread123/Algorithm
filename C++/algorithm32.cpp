#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> memo;
int lcs_memoization(const string& X, const string& Y, int m, int n) {
    if (m == 0 || n == 0) {
        return 0;
    }
    if (memo[m][n] != -1) {
        return memo[m][n];
    }
    if (X[m - 1] == Y[n - 1]) {
        return memo[m][n] = 1 + lcs_memoization(X, Y, m - 1, n - 1);
    }
    else {
        return memo[m][n] = max(lcs_memoization(X, Y, m - 1, n), lcs_memoization(X, Y, m, n - 1));
    }
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        string X, Y;
        cin >> X >> Y;
        int m = X.length();
        int n = Y.length();
        memo.assign(m + 1, vector<int>(n + 1, -1));
        cout << lcs_memoization(X, Y, m, n) << endl;
    }
    return 0;
}
