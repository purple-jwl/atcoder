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
// const ll INF = 1LL << 60;
// const int MOD = 1000000007;

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<pii>> vv(n);
  rep(i, m) {
    int p, y;
    cin >> p >> y;
    vv[p - 1].eb(mp(y, i));
  }
  vector<pair<int, pii>> ans;
  rep(i, n) {
    sort(all(vv[i]));
    rep(j, vv[i].size()) { ans.eb(mp(vv[i][j].S, mp(i + 1, j + 1))); }
  }
  sort(all(ans));
  rep(i, ans.size()) { printf("%06d%06d\n", ans[i].S.F, ans[i].S.S); }
}
