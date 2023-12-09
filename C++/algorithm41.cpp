#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
struct Node {
    int to;
    int weight;
    Node(int t, int w) : to(t), weight(w) {}
};
int dijkstra(vector<vector<Node>>& graph, int start) {
    int n = graph.size();
    vector<int> dist(n, INT_MAX);
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, start));
    vector<int> prevWeight(n, 0);
    int totalEdgeWeight = 0;
    while (!pq.empty()) {
        int u = pq.top().second;
        int uDist = pq.top().first;
        pq.pop();
        if (uDist > dist[u]) continue;
        for (const auto& neighbor : graph[u]) {
            int v = neighbor.to;
            int weight = neighbor.weight;
            if (dist[v] > dist[u] + weight) {
                totalEdgeWeight -= prevWeight[v];
                prevWeight[v] = weight;
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
                totalEdgeWeight += weight;
            }
        }
    }
    return totalEdgeWeight;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<Node>> graph(n);
        for (int i = 0; i < n; ++i) {
            int node, m;
            cin >> node >> m;
            for (int j = 0; j < m; ++j) {
                int neighbor, weight;
                cin >> neighbor >> weight;
                graph[node - 1].push_back(Node(neighbor - 1, weight));
            }
        }
        int totalEdgeWeight = dijkstra(graph, 0);
        cout << totalEdgeWeight << endl;
    }
    return 0;
}