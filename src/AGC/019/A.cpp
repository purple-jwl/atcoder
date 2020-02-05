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
  ll q, h, s, d, n;
  cin >> q >> h >> s >> d >> n;

  n *= 4;
  ll ans = 0;
  ll tmp;
  tmp = n / 8;
  n %= 8;
  ans = min({tmp * d, tmp * 2 * s, tmp * 4 * h, tmp * 8 * q});
  tmp = n / 4;
  n %= 4;
  ans += min({tmp * s, tmp * 2 * h, tmp * 4 * q});
  tmp = n / 2;
  n %= 2;
  ans += min({tmp * h, tmp * 2 * q});
  if (n) ans += q;

  cout << ans << endl;
}
