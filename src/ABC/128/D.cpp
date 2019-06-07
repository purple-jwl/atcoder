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
// const int MOD = 1000000007;

int main() {
  int N, K;
  cin >> N >> K;

  vector<int> V(N);
  rep (i, N) cin >> V[i];

  vector<int> lSum(N + 1, 0), rSum(N + 1, 0);
  rep (i, N) {
    lSum[i + 1] = lSum[i] + V[i];
    rSum[i + 1] = rSum[i] + V[N - i - 1];
  }

  vector<vector<int>> lMinusSum(N + 1, vector<int>(N + 1, 0)), rMinusSum(N + 1, vector<int>(N + 1, 0));
  vector<int> lTmp, rTmp;
  rep (i, N) {
    lTmp.eb(V[i]);
    rTmp.eb(V[N - i - 1]);

    sort(all(lTmp));
    sort(all(rTmp));

    int l = 0, r = 0;
    rep (j, i + 1) {
      if (lTmp[j] < 0) l += lTmp[j];
      if (rTmp[j] < 0) r += rTmp[j];
      lMinusSum[i + 1][j + 1] = l;
      rMinusSum[i + 1][j + 1] = r;
    }
  }

  int ans = 0;
  for (int i = 0; i <= N; i++) {
    for (int j = 0; j <= N; j++) {
      if (i + j > K || i + j > N) break;
      int ret = K - i - j;
      for (int p = 0; p <= i; p++) {
        for (int q = 0; q <= j; q++) {
          if (p + q > ret || p + q > N) break;
          ans = max(ans, lSum[i] + rSum[j] - lMinusSum[i][p] - rMinusSum[j][q]);
        }
      }
    }
  }

  cout << ans << endl;
}
