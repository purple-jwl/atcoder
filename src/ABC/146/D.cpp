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
// const ll INF = 1LL << 60;
// const ll MOD = 1000000007;

int main() {
  int n;
  cin >> n;
  vector<vector<pii>> edge(n, vector<pii>());
  rep(i, n - 1) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    edge[a].eb(mp(b, i));
    edge[b].eb(mp(a, i));
  }

  int ans = 0;
  rep(i, n) ans = max(ans, (int)edge[i].size());
  vector<int> color(n - 1, -1);

  queue<int> Q;
  Q.push(0);

  while (!Q.empty()) {
    int cur = Q.front();
    Q.pop();
    vector<bool> used(ans, 0);
    rep(i, edge[cur].size()) {
      int next = edge[cur][i].F;
      int idx = edge[cur][i].S;
      if (color[idx] != -1) used[color[idx]] = 1;
    }
    int idx2 = 0;
    rep(i, edge[cur].size()) {
      int next = edge[cur][i].F;
      int idx = edge[cur][i].S;
      if (color[idx] != -1) continue;
      while (used[idx2]) idx2++;
      color[idx] = idx2++;
      Q.push(next);
    }
  }

  cout << ans << endl;
  rep(i, n - 1) cout << color[i] + 1 << endl;
}
