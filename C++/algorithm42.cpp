#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
#define MAX_NODES 1001
struct Edge {
    int to, weight;
    Edge(int t, int w) : to(t), weight(w) {}
};
int primMST(vector<vector<Edge>>& graph, int n) {
    vector<bool> visited(n + 1, false);
    vector<int> minWeight(n + 1, INT_MAX);
    int totalWeight = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});
    minWeight[1] = 0;
    while (!pq.empty()) {
        int u = pq.top().second;
        int w = pq.top().first;
        pq.pop();
        if (visited[u]) continue;
        visited[u] = true;
        totalWeight += w;
        for (Edge& e : graph[u]) {
            if (!visited[e.to] && e.weight < minWeight[e.to]) {
                minWeight[e.to] = e.weight;
                pq.push({e.weight, e.to});
            }
        }
    }
    return totalWeight;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<Edge>> graph(n + 1);
        for (int i = 1; i <= n; ++i) {
            int k, m;
            cin >> k >> m;
            while (m--) {
                int v, w;
                cin >> v >> w;
                graph[k].push_back(Edge(v, w));
                graph[v].push_back(Edge(k, w));
            }
        }
        int result = primMST(graph, n);
        cout << result << endl;
    }
    return 0;
}