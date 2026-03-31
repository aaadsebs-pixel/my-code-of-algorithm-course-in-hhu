#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int sx, sy, fx, fy;
bool reachable = false;

vector<vector<int>> blocked;
vector<vector<int>> visited;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main() {
    cin >> n >> m;
    sx = 0, sy = 0, fx = n - 1, fy = m - 1;

    blocked.assign(n, vector<int>(m, 0));
    visited.assign(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            blocked[i][j] = (c == '#');
        }
    }

    if (blocked[sx][sy] || blocked[fx][fy]) {
        cout << "No" << endl;
        return 0;
    }

    queue<pair<int, int>> q;
    visited[sx][sy] = 1;
    q.push({sx, sy});

    while (!q.empty() && !reachable) {
        auto [x, y] = q.front();
        q.pop();

        if (x == fx && y == fy) {
            reachable = true;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (blocked[nx][ny] || visited[nx][ny]) continue;

            visited[nx][ny] = 1;
            q.push({nx, ny});
        }
    }

    cout << (reachable ? "Yes" : "No") << endl;
    return 0;
}