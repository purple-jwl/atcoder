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

int n, m, q;
int a[50], b[50], c[50], d[50];
ll ans = 0;

void rec(vector<int> x, int mv) {
  if (x.size() == n) {
    ll cnt = 0;
    rep(i, q) {
      if (x[b[i] - 1] - x[a[i] - 1] == c[i]) cnt += d[i];
    }
    ans = max(ans, cnt);
  } else {
    REP(i, mv, m + 1) {
      vector<int> _x = x;
      _x.eb(i);
      rec(_x, i);
    }
  }
}

int main() {
  cin >> n >> m >> q;
  rep(i, q) { cin >> a[i] >> b[i] >> c[i] >> d[i]; }

  rec(vector<int>(), 1);

  cout << ans << endl;
}
