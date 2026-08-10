#include <bits/stdc++.h>
using namespace std;

const int diff[5] = {0, -1, 0, 1, 0};
string dir = "LURD";

string getPath(int prow, int pcol, vector<string>& g) {
    string ans = "";

    while (g[prow][pcol] != 'A') {
        char ch = g[prow][pcol];
        ans += ch;

        if (ch == 'L')
            pcol++;
        else if (ch == 'R')
            pcol--;
        else if (ch == 'U')
            prow++;
        else if (ch == 'D')
            prow--;
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

void solve() {
    int R, C;
    cin >> R >> C;

    vector<string> g(R);

    for (int r = 0; r < R; r++)
        cin >> g[r];

    queue<pair<int, int>> q;

    // Find A
    for (int row = 0; row < R; row++) {
        bool foundA = false;

        for (int col = 0; col < C; col++) {
            if (g[row][col] == 'A') {
                q.push({row, col});
                foundA = true;
                break;
            }
        }

        if (foundA)
            break;
    }

    int hops = 0;
    int brow = -1, bcol = -1;
    bool found = false;

    while (!q.empty()) {
        auto [row, col] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ar = row + diff[i];
            int ac = col + diff[i + 1];

            // Check boundaries
            if (ar >= 0 && ar < R && ac >= 0 && ac < C) {

                // Move to an unvisited floor
                if (g[ar][ac] == '.') {
                    g[ar][ac] = dir[i];
                    q.push({ar, ac});
                }

                // Found B
                else if (g[ar][ac] == 'B') {
                    g[ar][ac] = dir[i];

                    brow = ar;
                    bcol = ac;
                    found = true;

                    string path = getPath(brow, bcol, g);

                    cout << "YES\n";
                    cout << path.length() << "\n";
                    cout << path << "\n";

                    return;
                }
            }
        }
    }

    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
