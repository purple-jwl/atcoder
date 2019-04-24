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

const int INF = 1 << 30;
// const ll INF = 1LL << 60;
// const int MOD = 1000000007;

int main() {
  int n, h;
  cin >> n >> h;

  vector<int> a(n), b(n);
  rep (i, n) cin >> a[i] >> b[i];

  sort(rall(a));
  sort(rall(b));

  int ans = h / a[0] + (h % a[0] ? 1 : 0);
  ll bSum = 0;
  rep (i, sz(b)) {
    if (a[0] >= b[i]) break;
    bSum += b[i];
    int tmp = h - bSum;
    if (tmp <= 0) {
      ans = min(ans, i + 1);
      break;
    } else {
      ans = min(ans, tmp / a[0] + (tmp % a[0] ? 1 : 0) + i + 1);
    }
  }

  cout << ans << endl;
}
