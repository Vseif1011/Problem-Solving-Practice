#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> players;
vector<int> color;
bool ok;

void dfs(int node, int c) {
    color[node] = c;

    for (auto child : players[node]) {
        if (color[child] == -1) {
            dfs(child, 1 - c);
        } 
        else if (color[child] == c) {
            ok = false;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    players.resize(n);
    color.assign(n, -1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;

        players[u].push_back(v);
        players[v].push_back(u);
    }

    int playersToBeKicked = 0;

    for (int i = 0; i < n; i++) {
        if (color[i] == -1) {
            ok = true;
            dfs(i, 0);

            if (!ok) {
                playersToBeKicked++;
            }
        }
    }

    cout << playersToBeKicked;
}