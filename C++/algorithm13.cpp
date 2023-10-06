#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int calculateWeight(const string& s) {
    int weight = 0;
    for (int i = 0; i < s.length(); i++) {
        if (i % 2 == 0) {
            weight += s[i] - 'a';
        } else {
            weight -= s[i] - 'a';
        }
    }
    return weight;
}
int countPositiveWeightPermutations(const string& s) {
    int count = 0;
    string sortedS = s;
    sort(sortedS.begin(), sortedS.end());

    do {
        int weight = calculateWeight(sortedS);
        if (weight > 0) {
            count++;
        }
    } while (next_permutation(sortedS.begin(), sortedS.end()));

    return count;
}
int main() {
    int t;
    cin >> t;
    cin.ignore();
    for (int i = 0; i < t; i++) {
        string s;
        getline(cin, s);
        int result = countPositiveWeightPermutations(s);
        cout << result << endl;
    }
    return 0;
}
