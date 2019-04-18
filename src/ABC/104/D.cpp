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
const int MOD = 1000000007;

ll dp[100000 + 1][3 + 1];

int main() {
  string s;
  cin >> s;

  dp[0][0] = 1;

  rep (i, sz(s)) {
    char ch = s[i];
    rep (j, 4) {
      if (ch == '?') dp[i + 1][j] = dp[i][j] * 3 % MOD;
      else dp[i + 1][j] = dp[i][j];
    }
    if (ch == 'A' || ch == '?') dp[i + 1][1] = (dp[i + 1][1] + dp[i][0]) % MOD;
    if (ch == 'B' || ch == '?') dp[i + 1][2] = (dp[i + 1][2] + dp[i][1]) % MOD;
    if (ch == 'C' || ch == '?') dp[i + 1][3] = (dp[i + 1][3] + dp[i][2]) % MOD;
  }

  cout << dp[sz(s)][3] << endl;
}
