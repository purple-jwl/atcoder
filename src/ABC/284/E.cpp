#include <bits/stdc++.h>

#define REP(i, x, n) for (int i = x; i < (int)(n); i++)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define uniq(x) x.erase(unique(x.begin(), x.end()), x.end())

using namespace std;

typedef long long ll;

int ans;
vector<int> edge[200000];
bool vis[200000];

void dfs(int u) {
  if (ans == 1000000) return;

  ans++;
  vis[u] = true;

  rep(i, edge[u].size()) {
    int v = edge[u][i];
    if (!vis[v]) {
      dfs(v);
    }
  }

  vis[u] = false;
}

int main() {
  int n, m;
  cin >> n >> m;
  rep(i, m) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  ans = 0;
  memset(vis, false, sizeof(vis));
  dfs(0);
  cout << ans << endl;
}
