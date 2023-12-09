#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_NODES 1001
struct Edge {
    int from, to, weight;
    Edge(int f, int t, int w) : from(f), to(t), weight(w) {}
};
bool compareEdges(const Edge &a, const Edge &b) {
    return a.weight < b.weight;
}
struct DisjointSet {
    vector<int> parent, rank;
    DisjointSet(int n) {
        parent.resize(n);
        rank.assign(n, 0);
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }
    int find(int u) {
        if (parent[u] != u)
            parent[u] = find(parent[u]);
        return parent[u];
    }
    void merge(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY])
                swap(rootX, rootY);
            parent[rootY] = rootX;
            if (rank[rootX] == rank[rootY])
                rank[rootX]++;
        }
    }
};
int kruskalMST(vector<Edge> &edges, int n) {
    sort(edges.begin(), edges.end(), compareEdges);

    DisjointSet ds(n + 1);
    int totalWeight = 0;
    for (Edge &e : edges) {
        int rootX = ds.find(e.from);
        int rootY = ds.find(e.to);
        if (rootX != rootY) {
            totalWeight += e.weight;
            ds.merge(rootX, rootY);
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
        vector<Edge> edges;
        for (int i = 1; i <= n; ++i) {
            int k, m;
            cin >> k >> m;
            while (m--) {
                int v, w;
                cin >> v >> w;
                edges.push_back(Edge(k, v, w));
            }
        }
        int result = kruskalMST(edges, n);
        cout << result << endl;
    }
    return 0;
}