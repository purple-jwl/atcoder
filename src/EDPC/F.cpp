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

int dp[3001][3001];

int main() {
  string s, t;
  cin >> s >> t;

  rep (i, sz(s)) rep (j, sz(t)) {
    if (s[i] == t[j]) dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 1);
    else dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
  }

  string ans = "";
  int a = sz(s);
  int b = sz(t);
  while (a > 0 && b > 0) {
    if (s[a - 1] == t[b - 1] && dp[a][b] == dp[a - 1][b - 1] + 1) {
      ans += s[a - 1];
      a--;
      b--;
    } else if (dp[a][b] == dp[a - 1][b]) {
      a--;
    } else {
      b--;
    }
  }

  reverse(all(ans));

  cout << ans << endl;
}
