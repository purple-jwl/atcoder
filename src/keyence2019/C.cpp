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
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  ll aSum = 0, bSum = 0;
  rep(i, n) {
    cin >> a[i];
    aSum += a[i];
  }
  rep(i, n) {
    cin >> b[i];
    bSum += b[i];
  }

  if (aSum < bSum) {
    cout << "-1" << endl;
    return 0;
  }

  vector<int> minus, plus;
  rep(i, n) {
    if (a[i] < b[i]) {
      minus.eb(b[i] - a[i]);
    }
    if (a[i] > b[i]) {
      plus.eb(a[i] - b[i]);
    }
  }

  sort(rall(plus));

  int idx = 0;
  rep(i, sz(minus)) {
    while (1) {
      if (plus[idx] == 0) idx++;
      int t = min(minus[i], plus[idx]);
      minus[i] -= t;
      plus[idx] -= t;
      if (minus[i] == 0) break;
    }
  }

  int ans = sz(minus);
  if (ans > 0) ans += idx + 1;

  cout << ans << endl;
}
