#include <iostream>
#include <queue>
using namespace std;
const int MAX = 100;
void bfs(int graph[MAX][MAX], int start, int numNodes) {
    bool visited[MAX] = {false};
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "BFS Traversal starting from node " << start << ": ";

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        cout << current << " ";

        for (int i = 0; i < numNodes; ++i) {
            if (graph[current][i] && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
    cout << endl;
}

int main() {
    int numNodes;
    cout << "Enter the number of nodes: ";
    cin >> numNodes;
   int graph[MAX][MAX];
    cout << "Enter the adjacency matrix:\n";
    for (int i = 0; i < numNodes; ++i) {
        for (int j = 0; j < numNodes; ++j) {
            cin >> graph[i][j];
        }
    }

    int startNode;
    cout << "Enter the starting node: ";
    cin >> startNode;

    bfs(graph, startNode, numNodes);

    return 0;
}