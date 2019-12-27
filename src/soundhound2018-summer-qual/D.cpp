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

/* --- INFやMODの値が適切か確認する --- */
// const int INF = 1 << 30;
const ll INF = 1LL << 60;
// const ll MOD = 1000000007;

vector<pair<int, pii>> edge[200000];
ll yenCost[200000], snuukCost[200000];

void bfs1(int start) {
  priority_queue<pll, vector<pll>, greater<pll>> pq;
  pq.push(mp(start, 0));

  while (!pq.empty()) {
    int cur = pq.top().F;
    ll cost = pq.top().S;
    pq.pop();

    rep(i, edge[cur].size()) {
      int next = edge[cur][i].F;
      ll nextCost = edge[cur][i].S.F;
      if (yenCost[next] <= yenCost[cur] + nextCost) continue;
      yenCost[next] = yenCost[cur] + nextCost;
      pq.push(mp(next, yenCost[next]));
    }
  }
}

void bfs2(int start) {
  priority_queue<pll, vector<pll>, greater<pll>> pq;
  pq.push(mp(start, 0));

  while (!pq.empty()) {
    int cur = pq.top().F;
    ll cost = pq.top().S;
    pq.pop();

    rep(i, edge[cur].size()) {
      int next = edge[cur][i].F;
      ll nextCost = edge[cur][i].S.S;
      if (snuukCost[next] <= snuukCost[cur] + nextCost) continue;
      snuukCost[next] = snuukCost[cur] + nextCost;
      pq.push(mp(next, snuukCost[next]));
    }
  }
}

int main() {
  int n, m, s, t;
  cin >> n >> m >> s >> t;
  s--;
  t--;
  rep(i, m) {
    int u, v, a, b;
    cin >> u >> v >> a >> b;
    u--;
    v--;
    edge[u].eb(mp(v, mp(a, b)));
    edge[v].eb(mp(u, mp(a, b)));
  }

  rep(i, n) yenCost[i] = snuukCost[i] = INF;

  yenCost[s] = 0;
  bfs1(s);

  snuukCost[t] = 0;
  bfs2(t);

  const ll ini = 1000000000000000;
  vector<ll> ans(n, 0);
  for (int i = n - 1; i >= 0; i--) {
    ans[i] = max(ans[i], ini - yenCost[i] - snuukCost[i]);
    if (i) ans[i - 1] = ans[i];
  }

  rep(i, n) cout << ans[i] << endl;
}
