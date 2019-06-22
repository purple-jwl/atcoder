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

// const int INF = 1 << 29;
// const ll INF = 1LL << 60;
// const int MOD = 1000000007;

int cnt[100005][30];

int main() {
  int N, C;
  cin >> N >> C;

  rep (i, N) {
    int s, t, c;
    cin >> s >> t >> c;
    cnt[s - 1][c - 1]++;
    cnt[t][c - 1]--;
  }

  rep (i, 100005) rep (j, C) {
    cnt[i + 1][j] += cnt[i][j];
    if (cnt[i][j] > 0) cnt[i][j] = 1;
  }

  int ans = 0;
  rep (i, 100005) {
    int sum = 0;
    rep (j, C) sum += cnt[i][j];
    ans = max(ans, sum);
  }

  cout << ans << endl;
}
