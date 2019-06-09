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

string L;
ll dp[100000 + 5][2]; // 1: ギリギリ / 0: 余裕あり

int main() {
  cin >> L;

  int n = sz(L);

  dp[0][1] = 2;
  dp[0][0] = 1;

  REP (i, 1, n) {
    if (L[i] == '1') {
      dp[i][1] = dp[i - 1][1] * 2 % MOD;
      dp[i][0] = (dp[i - 1][1] + dp[i - 1][0] * 3) % MOD;
    } else {
      dp[i][1] = dp[i - 1][1];
      dp[i][0] = dp[i - 1][0] * 3 % MOD;
    }
  }

  cout << (dp[n - 1][0] + dp[n - 1][1]) % MOD << endl;
}
