#include <iostream>
using namespace std;
//재귀함수로 스트링 뒤집기 구현
string reverse(string s) {
    if (s.length() == 0) {
        return s;
    } else {
        cout << s[s.length() - 1];
        return reverse(s.substr(0, s.length() - 1));
    }
}
int main() {
    int numTestCases;
    cin >> numTestCases;
    for (int i = 0; i < numTestCases; ++i) {
        string s;
        cin >> s;
        reverse(s);
        cout << endl;
    }
}