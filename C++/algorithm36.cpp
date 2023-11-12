#include <iostream>
#include <vector>
#include <climits>
using namespace std;
void buildExpression(int i, int j, const vector<vector<int>>& bracket, string& expression);
pair<int, string> matrixChainOrder(const vector<int>& dimensions) {
    int n = dimensions.size() - 1;
    vector<vector<int>> dp(n, vector<int>(n, 0));
    vector<vector<int>> bracket(n, vector<int>(n, 0));
    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; ++k) {
                int cost = dp[i][k] + dp[k + 1][j] + dimensions[i] * dimensions[k + 1] * dimensions[j + 1];
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                    bracket[i][j] = k;
                }
            }
        }
    }
    string expression;
    int minMultiplications = dp[0][n - 1];
    buildExpression(0, n - 1, bracket, expression);
    return make_pair(minMultiplications, expression);
}
void buildExpression(int i, int j, const vector<vector<int>>& bracket, string& expression) {
    if (i == j) {
        expression += "M" + to_string(i + 1);
    } else {
        expression += "(";
        buildExpression(i, bracket[i][j], bracket, expression);
        buildExpression(bracket[i][j] + 1, j, bracket, expression);
        expression += ")";
    }
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> dimensions(n + 1);
        for (int i = 0; i <= n; ++i) {
            cin >> dimensions[i];
        }
        pair<int, string> result = matrixChainOrder(dimensions);
        cout << result.second << endl;
        cout << result.first << endl;
    }
    return 0;
}
