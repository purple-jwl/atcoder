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
const ll MOD = 1000000007;

int main() {
  int n;
  cin >> n;
  vector<int> idx(200001, -1), next(n, -1);
  rep(i, n) {
    int c;
    cin >> c;
    if (idx[c] != -1) next[idx[c]] = i;
    idx[c] = i;
  }

  vector<ll> dp(n + 1, 0);
  dp[0] = 1;
  rep(i, n) {
    dp[i + 1] = (dp[i + 1] + dp[i]) % MOD;
    if (next[i] != -1 && next[i] != i + 1) dp[next[i]] = dp[i];
  }

  cout << dp[n] << endl;
}
