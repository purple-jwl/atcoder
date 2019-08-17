#include <bits/stdc++.h>

#define REP(i, x, n) for (int i = x; i < (int)(n); i++)
#define rep(i, n) REP(i, 0, n)
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
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

typedef long long ll;

/* --- INFの値が適切か確認する --- */
// const int INF = 1 << 30;
const ll INF = 1LL << 60;
// const int MOD = 1000000007;

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<pii>> edge(n), redge(n);
  rep(i, m) {
    int a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    edge[a].eb(mp(b, c));
    redge[b].eb(mp(a, c));
  }

  vector<bool> visited(n, false);
  visited[n - 1] = true;
  queue<int> Q;
  Q.push(n - 1);
  while (!Q.empty()) {
    int cur = Q.front();
    Q.pop();
    rep(i, redge[cur].size()) {
      int next = redge[cur][i].F;
      if (visited[next]) continue;
      visited[next] = true;
      Q.push(next);
    }
  }

  vector<ll> d(n, -INF);
  d[0] = 0;
  bool updated = true;
  rep(_, 2 * n) {
    updated = false;
    rep(i, n) if (d[i] != -INF) rep(j, edge[i].size()) {
      int next = edge[i][j].F;
      int cost = edge[i][j].S;
      if (d[next] < d[i] + cost) {
        d[next] = d[i] + cost;
        updated |= visited[next];
      }
    }
  }

  if (updated)
    cout << "inf" << endl;
  else
    cout << d[n - 1] << endl;
}
