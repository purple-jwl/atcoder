#include <bits/stdc++.h>

#define REP(i, x, n) for (int i = x; i < (int)(n); i++)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define uniq(x) x.erase(unique(x.begin(), x.end()), x.end())

using namespace std;

typedef long long ll;

int n, m;
vector<int> edge[200000];
bool vis[200000];

pair<int, int> dfs(int u) {
  vis[u] = true;

  int a = 1;
  int b = edge[u].size();
  rep(i, edge[u].size()) {
    int v = edge[u][i];
    if (!vis[v]) {
      auto p = dfs(v);
      a += p.first;
      b += p.second;
    }
  }

  return make_pair(a, b);
}

int main() {
  cin >> n >> m;
  rep(i, m) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    edge[u].push_back(v);
    edge[v].push_back(u);
  }

  memset(vis, false, sizeof(vis));

  rep(i, n) if (!vis[i]) {
    auto p = dfs(i);
    if (p.first != p.second / 2) {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
}
