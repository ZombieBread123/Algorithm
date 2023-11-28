#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
void iterativeDFS(int start, vector<bool> &visited, vector<vector<int>> &adjacencyList, int &nodeCount) {
    stack<int> stack;
    stack.push(start);
    visited[start] = true;
    nodeCount++;
    while (!stack.empty()) {
        int node = stack.top();
        stack.pop();
        for (int neighbor : adjacencyList[node]) {
            if (!visited[neighbor]) {
                stack.push(neighbor);
                visited[neighbor] = true;
                nodeCount++;
            }
        }
    }
}
void findConnectedComponents(int n, vector<vector<int>> &adjacencyList) {
    vector<bool> visited(n + 1, false);
    vector<int> componentSizes;
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            int nodeCount = 0;
            iterativeDFS(i, visited, adjacencyList, nodeCount);
            componentSizes.push_back(nodeCount);
        }
    }
    sort(componentSizes.begin(), componentSizes.end());
    cout << componentSizes.size() << " ";
    for (int size : componentSizes) {
        cout << size << " ";
    }
    cout << endl;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> adjacencyList(n + 1);
        for (int i = 1; i <= n; ++i) {
            int k, m;
            cin >> k >> m;
            while (m--) {
                int neighbor;
                cin >> neighbor;
                adjacencyList[k].push_back(neighbor);
                adjacencyList[neighbor].push_back(k);
            }
        }
        findConnectedComponents(n, adjacencyList);
    }
    return 0;
}