#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
pair<int, string> LCS(const string& X, const string& Y) {
    int m = X.length();
    int n = Y.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    int length = dp[m][n];
    string lcs;
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs = X[i - 1] + lcs;
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    return {length, lcs};
}
int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        string X, Y;
        cin >> X >> Y;
        pair<int, string> result = LCS(X, Y);
        cout << result.first << " " << result.second << endl;
    }
    return 0;
}
