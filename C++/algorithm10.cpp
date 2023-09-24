#include <iostream>
#include <vector>
using namespace std;
const int MOD = 1000;
vector<vector<int>> matrixMultiply(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                C[i][j] += (A[i][k] * B[k][j]) % MOD;
                C[i][j] %= MOD;
            }
        }
    }
    return C;
}
vector<vector<int>> matrixPower(const vector<vector<int>>& A, long long exponent) {
    int n = A.size();
    if (exponent == 0 || exponent == 1) {
        return A;
    }
    if (exponent % 2 == 0) {
        vector<vector<int>> halfPower = matrixPower(A, exponent / 2);
        return matrixMultiply(halfPower, halfPower);
    } else {
        vector<vector<int>> halfPower = matrixPower(A, (exponent - 1) / 2);
        vector<vector<int>> temp = matrixMultiply(halfPower, halfPower);
        return matrixMultiply(temp, A);
    }
}
int fibonacci(int n) {
    if (n == 0) {
        return 0;
    }
    vector<vector<int>> F = {{1, 1}, {1, 0}};
    F = matrixPower(F, n - 1);
    return F[0][0];
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int result = fibonacci(n);
        cout << result << endl;
    }
    return 0;
}