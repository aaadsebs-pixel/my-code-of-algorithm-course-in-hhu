#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int n, m, t;
int sx, sy, fx, fy;
long long ans = 0;

vector<vector<int>> blocked;
vector<vector<int>> visited;


int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main() {
    cin >> n >> m >> t;
    cin >> sx >> sy >> fx >> fy;

    blocked.assign(n + 1, vector<int>(m + 1, 0));
     visited.assign(n + 1, vector<int>(m + 1, 0));
    //这一行相当与声明这个数组有多大，这个数组是n+1个元素，每个元素是一个m+1大小的数组，数组中的每个元素初始值为0

    for (int i = 0; i < t; i++) {
        int x, y;
        cin >> x >> y;
        blocked[x][y] = 1;
    }

    if (blocked[sx][sy] || blocked[fx][fy]) {
        cout << 0 << '\n';
        return 0;//如果起点或者终点是障碍物，属于防御型
    }

    struct Frame {
        int x, y, dir; // dir: 下一个要尝试的方向 [0..4]
    };

    stack<Frame> st;
    visited[sx][sy] = 1;
    st.push({sx, sy, 0});

    while (!st.empty()) {
        Frame &cur = st.top();

        if (cur.x == fx && cur.y == fy) {
            ans++;
            visited[cur.x][cur.y] = 0; // 回溯算法，
            st.pop();
            continue;
        }

        if (cur.dir == 4) {
            visited[cur.x][cur.y] = 0; // 四个方向都试过，回溯
            st.pop();
            continue;
        }

        int i = cur.dir++;
        int nx = cur.x + dx[i];
        int ny = cur.y + dy[i];

        if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
        if (blocked[nx][ny] || visited[nx][ny]) continue;

        visited[nx][ny] = 1;
        st.push({nx, ny, 0});
    }

    cout << ans << '\n';
    return 0;
}