#include <iostream>
#include <vector>
#include <climits>
using namespace std;
vector<vector<int>> memo;
int matrixChainOrder(const vector<int>& dims, int i, int j) {
    if (i == j) return 0;
    if (memo[i][j] != -1) return memo[i][j];
    int minCost = INT_MAX;
    for (int k = i; k < j; ++k) {
        int cost = matrixChainOrder(dims, i, k) + matrixChainOrder(dims, k + 1, j) + dims[i - 1] * dims[k] * dims[j];
        minCost = min(minCost, cost);
    }
    return memo[i][j] = minCost;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> dims(n + 1);
        for (int i = 0; i <= n; ++i) {
            cin >> dims[i];
        }
        memo.assign(n + 1, vector<int>(n + 1, -1));
        cout << matrixChainOrder(dims, 1, n) << endl;
    }
    return 0;
}
