#include <bits/stdc++.h>

#define REP(i, x, n) for (int i = x; i < (int)(n); i++)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define uniq(x) x.erase(unique(x.begin(), x.end()), x.end())

using namespace std;

typedef long long ll;

const ll MAX = 1e18;

int main() {
  int n;
  cin >> n;
  vector<int> x(n), y(n), z(n);
  rep(i, n) cin >> x[i] >> y[i] >> z[i];

  int zsum = 0;
  rep(i, n) zsum += z[i];

  vector<ll> dp(100000 + 5, MAX);
  dp[0] = 0;

  rep(i, n) {
    for (int j = 100000; j >= 0; j--) {
      if (dp[j] == MAX) continue;
      ll v = (x[i] > y[i]) ? 0 : (y[i] + x[i] + 1) / 2 - x[i];
      dp[j + z[i]] = min(dp[j + z[i]], dp[j] + v);
    }
  }

  ll ans = MAX;
  REP(i, (zsum + 1) / 2, zsum + 1) ans = min(ans, dp[i]);

  cout << ans << endl;
}
