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
  int N, K;
  cin >> N >> K;
  vector<int> a(N);
  rep(i, N) cin >> a[i];

  vector<ll> sum;
  rep(i, N) {
    ll s = 0;
    REP(j, i, N) {
      s += a[j];
      sum.eb(s);
    }
  }

  ll ans = 0;
  for (int i = 60; i >= 0; i--) {
    vector<ll> tmp;
    rep(j, sz(sum)) if ((1LL << i) & sum[j]) tmp.eb(sum[j]);
    if (sz(tmp) >= K) {
      ans += (1LL << i);
      sum = tmp;
    }
  }

  cout << ans << endl;
}
