#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> adj;
vector<bool> vis1, vis2;

void dfs(int start) {
    stack<int> s;
    s.push(start);
    vis1[start] = true;
    cout << start << " ";

    while (!s.empty()) {
        int current = s.top();
        bool found = false;

        for (int i = 0; i < (int)adj[current].size(); i++) {
            int neighbor = adj[current][i];
            if (!vis1[neighbor]) {
                s.push(neighbor);
                vis1[neighbor] = true;
                cout << neighbor << " ";
                found = true;
                break;
            }
        }

        if (!found) {
            s.pop();
        }
    }
    cout << "\n";
}

void bfs(int start) {
    queue<int> q;
    q.push(start);
    vis2[start] = true;
    cout << start << " ";

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int neighbor : adj[current]) {
            if (!vis2[neighbor]) {
                q.push(neighbor);
                vis2[neighbor] = true;
                cout << neighbor << " ";
            }
        }
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; // n: 边数, m: 点数(点编号 1..m)
    cin >> n >> m;

    adj.resize(m + 1);
    vis1.assign(m + 1, false);
    vis2.assign(m + 1, false);

    for (int i = 1; i <= m; i++) {
        int a, c;
        cin >> a >> c;
        adj[a].push_back(c);     // 有向图
        // adj[c].push_back(a);  // 如果是无向图，取消注释
    }

    for (int i = 1; i <= m; i++) {
        sort(adj[i].begin(), adj[i].end());
    }

    dfs(1);
    bfs(1);

    return 0;
}
