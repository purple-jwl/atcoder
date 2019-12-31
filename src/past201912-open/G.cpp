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

int n;
int a[10][10];
ll ans = -INF;

void dfs(vector<int> x, vector<int> y, vector<int> z, int idx) {
  if (idx == n) {
    ll sum = 0;
    rep(i, x.size()) REP(j, i + 1, x.size()) sum += a[x[i]][x[j]];
    rep(i, y.size()) REP(j, i + 1, y.size()) sum += a[y[i]][y[j]];
    rep(i, z.size()) REP(j, i + 1, z.size()) sum += a[z[i]][z[j]];
    ans = max(ans, sum);
  } else {
    vector<int> _x, _y, _z;
    _x = x;
    _y = y;
    _z = z;
    _x.eb(idx);
    _y.eb(idx);
    _z.eb(idx);
    dfs(_x, y, z, idx + 1);
    dfs(x, _y, z, idx + 1);
    dfs(x, y, _z, idx + 1);
  }
}

int main() {
  cin >> n;
  REP(i, 0, n) REP(j, i + 1, n) cin >> a[i][j];
  dfs(vector<int>(), vector<int>(), vector<int>(), 0);
  cout << ans << endl;
}
