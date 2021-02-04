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
  vector<int> c(n);
  rep(i, n) cin >> c[i];

  int bmax = 0;
  int b = 0;
  int rmax = 0;
  int r = 0;
  rep(i, 2 * n) {
    if (c[i % n] == 0) {
      b = 0;
      rmax = max(rmax, ++r);
    } else {
      bmax = max(bmax, ++b);
      r = 0;
    }
  }

  int m = max(bmax, rmax);
  int ans = 1;
  if (m == 2 * n)
    ans = -1;
  else
    while (m >= 3) ans++, m -= 2;

  cout << ans << endl;
}
