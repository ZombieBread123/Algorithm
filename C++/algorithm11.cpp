//이분제곱과 재귀함수를 이용한 빠른 거듭제곱 구하기
#include <iostream>
using namespace std;
const int MOD = 1000;
int binaryPower(int a, int n) {
    if (n == 0) {
        return 1;
    }
    int half = binaryPower(a, n / 2);
    int result = (half * half) % MOD;
    if (n % 2 == 1) {
        result = (result * a) % MOD;
    }
    return result;
}
int main() {
    int numTestCases;
    cin >> numTestCases;
    for (int i = 0; i < numTestCases; ++i) {
        int a, b;
        cin >> a >> b;
        cout << binaryPower(a, b)<< endl;
    }
}