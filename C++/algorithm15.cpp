#include <iostream>
using namespace std;
unsigned long long pow(int x){
    unsigned long long result =1;
    for(int i = 0; i < x; i++){
        result *= 2;
    }
    return result;
}
void hanoi_tower(int n, int a, int b, int c, unsigned long long k, unsigned long long std, unsigned long long sstd) {
    if(k == std) {
        cout << a << " " << c << endl;
        return;
    }else if(k < std) {
        std -= sstd;
        sstd /= 2;
        hanoi_tower(n - 1, a, c, b, k, std, sstd);
    }else {
        std += sstd;
        sstd /= 2;
        hanoi_tower(n - 1, b, a, c, k, std, sstd);
    }
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        unsigned long long k;
        cin >> n >> k;
        unsigned long long std = 0;
        unsigned long long sstd = 0;
        std = pow(n - 1);
        sstd = std / 2;
        hanoi_tower(n, 1, 2, 3, k, std, sstd);
    }
    return 0;
}
