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

int h[100];
vector<int> edge[100];

int dfs(int cur, int prev) {
  int res = -1;
  if (h[cur]) res = 0;
  rep(i, edge[cur].size()) {
    int next = edge[cur][i];
    if (next == prev) continue;
    int tmp = dfs(next, cur);
    if (tmp != -1) {
      res = max(0, res);
      res += tmp + 1;
    }
  }
  return res;
}

int main() {
  int n, x;
  cin >> n >> x;
  x--;
  rep(i, n) cin >> h[i];
  rep(i, n - 1) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    edge[a].eb(b);
    edge[b].eb(a);
  }

  int ans = 0;
  rep(i, edge[x].size()) ans += 2 * (dfs(edge[x][i], x) + 1);

  cout << ans << endl;
}
