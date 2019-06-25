#include <bits/stdc++.h>

#define REP(i, x, n) for (int i = x; i < (int)(n); i++)
#define rep(i, n) REP (i, 0, n)
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

using namespace std;

typedef long long ll;

// const int INF = 1 << 30;
// const ll INF = 1LL << 60;
// const int MOD = 1000000007;

int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep (i, n) cin >> a[i];

  vector<int> l(n), r(n);
  rep (i, n) {
    if (i == 0) {
      l[0] = a[0];
      r[n - 1] = a[n - 1];
    } else {
      l[i] = gcd(l[i - 1], a[i]);
      r[n - 1 - i] = gcd(r[n - i], a[n - 1 - i]);
    }
  }

  int ans = 0;
  rep (i, n) {
    if (i == 0) ans = max(ans, r[i + 1]);
    else if (i == n - 1) ans = max(ans, l[i - 1]);
    else ans = max(ans, gcd(l[i - 1], r[i + 1]));
  }

  cout << ans << endl;
}
