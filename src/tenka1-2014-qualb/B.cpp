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
// const ll INF = 1LL << 60;
const ll MOD = 1000000007;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<string> t(n);
  rep(i, n) cin >> t[i];

  vector<ll> dp(s.size() + 1, 0);
  dp[0] = 1;

  rep(i, s.size()) if (dp[i]) rep(j, n) {
    if (i + t[j].size() > s.size()) continue;
    bool f = true;
    rep(k, t[j].size()) if (s[i + k] != t[j][k]) f = false;
    if (f) dp[i + t[j].size()] = (dp[i + t[j].size()] + dp[i]) % MOD;
  }

  cout << dp[s.size()] << endl;
}
