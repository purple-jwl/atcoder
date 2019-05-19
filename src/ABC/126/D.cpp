#include <bits/stdc++.h>

#define REP(i, x, n) for (int i = x; i < (int)(n); i++)
#define rep(i, n) REP (i, 0, n)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x.size())
#define popcount(x) __builtin_popcount(x)
#define popcountll(x) __builtin_popcountll(x)
#define uniq(x) x.erase(unique(x.begin(), x.end()), x.end())
#define F first
#define S second
#define mp make_pair
#define eb emplace_back

using namespace std;

typedef long long ll;

// const int INF = 1 << 30;
// const ll INF = 1LL << 60;
// const int MOD = 1000000007;

vector<pair<int, int>> edge[100000];
ll dist[100000];

void dfs(int cur, int prev, ll d) {
  dist[cur] = d;

  rep (i, edge[cur].size()) {
    if (prev != edge[cur][i].F) {
      dfs(edge[cur][i].F, cur, d + edge[cur][i].S);
    }
  }
}

int main() {
  int N;
  cin >> N;
  rep (i, N - 1) {
    int u, v, w;
    cin >> u >> v >> w;
    u--; v--;
    edge[u].eb(mp(v, w));
    edge[v].eb(mp(u, w));
  }

  dfs(0, 0, 0);

  rep (i, N) {
    if ((dist[i] - dist[0]) % 2) cout << '1' << endl;
    else cout << '0' << endl;
  }
}
