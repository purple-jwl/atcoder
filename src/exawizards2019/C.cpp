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
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  vector<char> t(q), d(q);
  rep(i, q) cin >> t[i] >> d[i];

  int l, r;
  // left side
  l = -1;
  r = n;
  while (r - l > 1) {
    int mid = (l + r) / 2;
    int pos = mid;

    bool f = false;
    rep(i, q) {
      if (t[i] != s[pos]) continue;
      pos = pos + (d[i] == 'L' ? -1 : 1);
      if (pos < 0) f = true;
      if (!(0 <= pos && pos < n)) break;
    }

    if (f)
      l = mid;
    else
      r = mid;
  }
  int lcnt = l + 1;

  // right side
  l = -1;
  r = n;
  while (r - l > 1) {
    int mid = (l + r) / 2;
    int pos = mid;

    bool f = false;
    rep(i, q) {
      if (t[i] != s[pos]) continue;
      pos = pos + (d[i] == 'L' ? -1 : 1);
      if (pos >= n) f = true;
      if (!(0 <= pos && pos < n)) break;
    }

    if (f)
      r = mid;
    else
      l = mid;
  }
  int rcnt = (n - r);

  cout << n - lcnt - rcnt << endl;
}
