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
const int INF = 1 << 30;
// const ll INF = 1LL << 60;
// const ll MOD = 1000000007;

int dp[1000000 + 5][2];

int main() {
  string s;
  cin >> s;

  reverse(all(s));
  s += '0';

  int n = s.size();

  rep(i, n + 1) rep(j, 2) dp[i][j] = INF;
  dp[0][0] = 0;

  rep(i, n) rep(j, 2) if (dp[i][j] != INF) {
    int d = s[i] - '0';
    dp[i + 1][0] = min(dp[i + 1][0], dp[i][j] + d + j);
    dp[i + 1][1] = min(dp[i + 1][1], dp[i][j] + 10 - d - j);
  }

  cout << dp[n][0] << endl;
}
