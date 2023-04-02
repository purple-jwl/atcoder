#include <bits/stdc++.h>

#define REP(i, x, n) for (int i = x; i < (int)(n); i++)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define uniq(x) x.erase(unique(x.begin(), x.end()), x.end())

using namespace std;

typedef long long ll;

int main() {
  int n, x;
  cin >> n >> x;
  vector<bool> dp(x + 1, 0);
  dp[0] = 1;
  rep(i, n) {
    int a, b;
    cin >> a >> b;
    rep(j, b) for (int k = x; k >= 0; k--) {
      if (dp[k] && k + a <= x) dp[k + a] = 1;
    }
  }

  cout << (dp[x] ? "Yes" : "No") << endl;
}
