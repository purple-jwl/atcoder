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
const ll MOD = 1000000007;

ll dp[100001][13];

int main() {
  string S;
  cin >> S;

  dp[0][0] = 1;
  rep(i, S.size()) rep(j, 13) if (dp[i][j] != 0) rep(k, 10) {
    if (S[i] != '?' && (S[i] - '0') != k) continue;
    int v = (j * 10 + k) % 13;
    dp[i + 1][v] += dp[i][j];
    dp[i + 1][v] %= MOD;
  }

  cout << dp[S.size()][5] << endl;
}

