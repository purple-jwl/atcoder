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

ll dp[1 << 10];

int main() {
  int n, m;
  cin >> n >> m;

  rep(i, (1 << n)) dp[i] = INF;
  dp[0] = 0;

  rep(i, m) {
    string s;
    ll c;
    cin >> s >> c;
    int bit = 0;
    rep(j, n) if (s[j] == 'Y') bit += (1 << j);
    rep(j, (1 << n)) if (dp[j] != INF) {
      dp[j | bit] = min(dp[j | bit], dp[j] + c);
    }
  }

  ll ans = dp[(1 << n) - 1];
  if (ans == INF) ans = -1;

  cout << ans << endl;
}
