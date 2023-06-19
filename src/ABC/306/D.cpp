#include <bits/stdc++.h>

#define REP(i, x, n) for (int i = x; i < (int)(n); i++)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define uniq(x) x.erase(unique(x.begin(), x.end()), x.end())

using namespace std;

typedef long long ll;

int main() {
  int n;
  cin >> n;

  vector<vector<ll>> dp(n + 1, vector<ll>(2, 0));
  rep(i, n) {
    ll x, y;
    cin >> x >> y;
    dp[i + 1][0] = dp[i][0];
    dp[i + 1][1] = dp[i][1];
    if (x == 0) {
      dp[i + 1][0] = max(dp[i + 1][0], max(dp[i][0] + y, 0LL));
      dp[i + 1][0] = max(dp[i + 1][0], max(dp[i][1] + y, 0LL));
    } else {
      dp[i + 1][1] = max(dp[i + 1][1], max(dp[i][0] + y, 0LL));
    }
  }

  cout << max(dp[n][0], dp[n][1]) << endl;
}
