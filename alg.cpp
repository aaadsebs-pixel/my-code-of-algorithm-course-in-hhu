#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[9][9] = {0};
int rowMask[9] = {0}, colMask[9] = {0}, boxMask[9] = {0};
vector<pair<int, int>> empties;

inline int boxId(int r, int c) {
    return (r / 3) * 3 + (c / 3);
}

inline int bitCount(int x) {
    int cnt = 0;
    while (x) {
        x &= (x - 1);
        ++cnt;
    }
    return cnt;
}

bool dfs(int idx) {
    if (idx == (int)empties.size()) return true;

    int best = -1, bestMask = 0, bestCnt = 10;

    for (int i = idx; i < (int)empties.size(); ++i) {
        int r = empties[i].first, c = empties[i].second;
        int used = rowMask[r] | colMask[c] | boxMask[boxId(r, c)];
        int can = (~used) & 0x3FE; // bit1..bit9
        int cnt = bitCount(can);
        if (cnt < bestCnt) {
            bestCnt = cnt;
            best = i;
            bestMask = can;
            if (cnt == 1) break;
        }
    }

    if (bestCnt == 0) return false;

    swap(empties[idx], empties[best]);
    int r = empties[idx].first, c = empties[idx].second, b = boxId(r, c);
    int can = bestMask;

    for (int d = 1; d <= 9; ++d) {
        int bit = 1 << d;
        if ((can & bit) == 0) continue;

        arr[r][c] = d;
        rowMask[r] |= bit;
        colMask[c] |= bit;
        boxMask[b] |= bit;

        if (dfs(idx + 1)) return true;

        rowMask[r] ^= bit;
        colMask[c] ^= bit;
        boxMask[b] ^= bit;
        arr[r][c] = 0;
    }

    swap(empties[idx], empties[best]);
    return false;
}

int main() {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cin >> arr[i][j];
            if (arr[i][j] == 0) {
                empties.push_back({i, j});
            } else {
                int bit = 1 << arr[i][j];
                rowMask[i] |= bit;
                colMask[j] |= bit;
                boxMask[boxId(i, j)] |= bit;
            }
        }
    }

    dfs(0);

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (j) cout << ' ';
            cout << arr[i][j];
        }
        cout << '\n';
    }
    return 0;
}
