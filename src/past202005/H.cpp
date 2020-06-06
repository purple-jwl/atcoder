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

int main() {
  int N, L;
  cin >> N >> L;
  vector<bool> d(100001, false);
  rep(i, N) {
    int x;
    cin >> x;
    d[x] = 1;
  }
  int T1, T2, T3;
  cin >> T1 >> T2 >> T3;

  vector<int> dp(L + 1, INF);
  dp[0] = 0;

  rep(i, L) {
    int c = 0;
    if (d[i]) c += T3;

    dp[i + 1] = min(dp[i + 1], dp[i] + c + T1);
    if (i + 2 <= L)
      dp[i + 2] = min(dp[i + 2], dp[i] + c + T1 + T2);
    else
      dp[i + 1] = min(dp[i + 1], dp[i] + c + T1 / 2 + T2 / 2);
    if (i + 4 <= L)
      dp[i + 4] = min(dp[i + 4], dp[i] + c + T1 + T2 * 3);
    else {
      if (i + 3 <= L)
        dp[i + 3] = min(dp[i + 3], dp[i] + c + T1 / 2 + T2 * 2 + T2 / 2);
      else if (i + 2 <= L)
        dp[i + 2] = min(dp[i + 2], dp[i] + c + T1 / 2 + T2 + T2 / 2);
      else if (i + 1 <= L)
        dp[i + 1] = min(dp[i + 1], dp[i] + c + T1 / 2 + T2 / 2);
    }
  }

  cout << dp[L] << endl;
}
