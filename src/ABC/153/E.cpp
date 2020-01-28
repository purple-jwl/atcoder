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
const ll INF = 1LL << 60;
// const ll MOD = 1000000007;

int main() {
  int h, n;
  cin >> h >> n;
  vector<int> a(n), b(n);
  rep(i, n) cin >> a[i] >> b[i];

  vector<ll> dp(h + 1, INF);
  dp[h] = 0;
  rep(i, n) for (int j = h; j > 0; j--) if (dp[j] != INF) {
    int v = max(0, j - a[i]);
    dp[v] = min(dp[v], dp[j] + b[i]);
  }

  cout << dp[0] << endl;
}
