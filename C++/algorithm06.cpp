#include <iostream>
using namespace std;
int fibo(int n) {
    if (n == 0) {
        return 0;
    }
    else if (n == 1) {
        return 1;
    } else {
        return fibo(n-1) + fibo(n-2);
    }
}
// ����Լ��� �̿��� �Ǻ���ġ ���� ����
int main() {
    int numTestCases;
    cin >> numTestCases;
    for (int i = 0; i < numTestCases; ++i) {
        int num;
        cin >> num;
        cout << fibo(num) << endl;
    }

}