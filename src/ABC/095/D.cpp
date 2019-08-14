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
  ll N, C;
  cin >> N >> C;
  vector<ll> x(N), v(N);
  rep(i, N) cin >> x[i] >> v[i];

  vector<ll> lsum(N), rsum(N);
  rep(i, N) {
    lsum[i] = v[i];
    if (i) lsum[i] += lsum[i - 1];
    rsum[i] = v[N - 1 - i];
    if (i) rsum[i] += rsum[i - 1];
  }

  vector<ll> l2sum = lsum, r2sum = rsum;
  rep(i, N) {
    lsum[i] -= x[i];
    l2sum[i] -= x[i] * 2;
    rsum[i] -= (C - x[N - 1 - i]);
    r2sum[i] -= (C - x[N - 1 - i]) * 2;
  }

  rep(i, N - 1) {
    lsum[i + 1] = max(lsum[i + 1], lsum[i]);
    l2sum[i + 1] = max(l2sum[i + 1], l2sum[i]);
    rsum[i + 1] = max(rsum[i + 1], rsum[i]);
    r2sum[i + 1] = max(r2sum[i + 1], r2sum[i]);
  }

  ll ans = 0;
  rep(i, N) ans = max({ans, lsum[i], rsum[i]});
  rep(i, N - 1) ans = max(
      {ans, l2sum[i] + rsum[N - 1 - i - 1], r2sum[i] + lsum[N - 1 - i - 1]});

  cout << ans << endl;
}
