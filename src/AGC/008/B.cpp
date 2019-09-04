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

  vector<ll> sum(N + 1, 0), psum(N + 1, 0);
  rep(i, N) {
    sum[i + 1] = sum[i] + a[i];
    psum[i + 1] = psum[i] + (a[i] > 0 ? a[i] : 0);
  }

  ll ans = 0;
  REP(i, K, N + 1)
  ans = max({ans, sum[i] - sum[i - K] + psum[i - K] + psum[N] - psum[i],
             psum[i - K] + psum[N] - psum[i]});

  cout << ans << endl;
}
