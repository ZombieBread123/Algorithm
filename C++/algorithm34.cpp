#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int matrixChainOrder(const vector<int>& dims, int i, int j) {
    if (i == j) {
        return 0;
    }
    int minOps = INT_MAX;
    for (int k = i; k < j; k++) {
        int ops = matrixChainOrder(dims, i, k) +
                  matrixChainOrder(dims, k + 1, j) +
                  dims[i - 1] * dims[k] * dims[j];
        if (ops < minOps) {
            minOps = ops;
        }
    }
    return minOps;
}
int main() {
    int t;
    cin >> t;
    for (int testCase = 0; testCase < t; testCase++) {
        int n;
        cin >> n;
        vector<int> dims(n + 1);
        for (int i = 0; i <= n; i++) {
            cin >> dims[i];
        }
        cout << matrixChainOrder(dims, 1, n) << endl;
    }
    return 0;
}
