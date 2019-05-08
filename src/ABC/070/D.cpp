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

void dfs(int cur, int prev) {
  rep (i, edge[cur].size()) {
    if (edge[cur][i].F == prev) continue;
    dist[edge[cur][i].F] = dist[cur] + edge[cur][i].S;
    dfs(edge[cur][i].F, cur);
  }
}

int main() {
  int N;
  cin >> N;

  rep (i, N - 1) {
    int a, b, c;
    cin >> a >> b >> c;
    edge[a - 1].eb(mp(b - 1, c));
    edge[b - 1].eb(mp(a - 1, c));
  }

  int Q, K;
  cin >> Q >> K;

  dfs(K - 1, K - 1);

  rep (i, Q) {
    int x, y;
    cin >> x >> y;
    cout << dist[x - 1] + dist[y - 1] << endl;
  }
}
