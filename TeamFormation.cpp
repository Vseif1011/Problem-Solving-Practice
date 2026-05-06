#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> color;
bool ok;

void dfs(int v, int c) {
    color[v] = c;

    for (int u : g[v]) {
        if (color[u] == -1) {
            dfs(u, 1 - c);
        } else if (color[u] == c) {
            ok = false;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    g.resize(n);
    color.assign(n, -1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        if (color[i] == -1) {
            ok = true;
            dfs(i, 0);

            if (!ok) ans++;
        }
    }

    if(((n-ans)%2!=0) || (ans==0 && n%2 !=0)) {
        ans++;
    }
    cout<<ans;
    
 }