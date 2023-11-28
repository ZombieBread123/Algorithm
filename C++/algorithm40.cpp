#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
class Node {
public:
    int id;
    vector<int> adj;
    Node(int _id) : id(_id) {}
};
class BiconnectedComponents {
public:
    vector<Node> graph;
    vector<bool> visited;
    vector<int> ids;
    vector<int> low;
    vector<int> articulationPoints;
    stack<pair<int, int>> edgeStack;
    int idCount;
    int numComponents;
    BiconnectedComponents(int n) : graph(n + 1, Node(0)), visited(n + 1, false), ids(n + 1, -1), low(n + 1, -1), idCount(0), numComponents(0) {}
    void addEdge(int u, int v) {
        graph[u].adj.push_back(v);
        graph[v].adj.push_back(u);
    }
    void dfs(int u, int parent = -1) {
        visited[u] = true;
        ids[u] = low[u] = idCount++;
        int children = 0;
        bool isArticulationPoint = false;
        for (int v : graph[u].adj) {
            if (v == parent)
                continue;
            if (!visited[v]) {
                children++;
                edgeStack.push({u, v});
                dfs(v, u);
                low[u] = min(low[u], low[v]);
                if ((parent == -1 && children > 1) || (parent != -1 && low[v] >= ids[u])) {
                    isArticulationPoint = true;
                }
                if (low[v] >= ids[u]) {
                    numComponents++;
                    while (true) {
                        pair<int, int> edge = edgeStack.top();
                        edgeStack.pop();
                        if (edge.first == u && edge.second == v)
                            break;
                    }
                }
            } else if (ids[v] < ids[u]) {
                low[u] = min(low[u], ids[v]);
                edgeStack.push({u, v});
            }
        }
        if (isArticulationPoint)
            articulationPoints.push_back(u);
    }
    void findBiconnectedComponents() {
        for (int i = 1; i < graph.size(); ++i) {
            if (!visited[i]) {
                dfs(i);
            }
        }
        cout << numComponents << endl;
        cout << articulationPoints.size() << " ";
        sort(articulationPoints.begin(), articulationPoints.end());
        for (int point : articulationPoints)
            cout << point << " ";
        cout << endl;
    }
};
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        BiconnectedComponents bc(n);
        for (int i = 1; i <= n; ++i) {
            int node, m;
            cin >> node >> m;
            for (int j = 0; j < m; ++j) {
                int neighbor;
                cin >> neighbor;
                bc.addEdge(node, neighbor);
            }
        }
        bc.findBiconnectedComponents();
    }
    return 0;
}