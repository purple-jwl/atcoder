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

ll nCr[2001][2001];

int main() {
  nCr[0][0] = 1;
  rep(i, 2000) rep(j, i + 1) {
    nCr[i + 1][j] = (nCr[i + 1][j] + nCr[i][j]) % MOD;
    if (j + 1 <= 2000)
      nCr[i + 1][j + 1] = (nCr[i + 1][j + 1] + nCr[i][j]) % MOD;
  }

  int N, K;
  cin >> N >> K;

  int red = N - K;

  REP(i, 1, K + 1) {
    ll ans = 0;
    if (red + 1 < i)
      cout << ans << endl;
    else {
      ans = nCr[red + 1][i] * nCr[K - 1][i - 1] % MOD;
      cout << ans << endl;
    }
  }
}
