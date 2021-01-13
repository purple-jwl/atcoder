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
// const int INF = 1 << 30;
const ll INF = 1LL << 60;
// const ll MOD = 1000000007;

int main() {
  int N, M;
  cin >> N >> M;
  vector<ll> A(N), dp(N, INF);
  rep(i, N) cin >> A[i];

  vector<int> edge[N];
  rep(i, M) {
    int x, y;
    cin >> x >> y;
    edge[x - 1].eb(y - 1);
  }

  rep(i, N) rep(j, edge[i].size()) {
    int e = edge[i][j];
    dp[e] = min({dp[e], dp[i], A[i]});
  }

  ll ans = -INF;
  rep(i, N) ans = max(ans, A[i] - dp[i]);

  cout << ans << endl;
}
