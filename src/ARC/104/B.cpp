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
// const ll MOD = 1000000007;

int cnt[5000][4];

int main() {
  int n;
  string s;
  cin >> n >> s;

  string t = "ATCG";

  rep(i, n) rep(j, 4) {
    if (i) cnt[i][j] = cnt[i - 1][j];
    if (s[i] == t[j]) cnt[i][j]++;
  }

  int ans = 0;
  rep(i, n) REP(j, i, n) {
    if ((cnt[j][0] - (i ? cnt[i - 1][0] : 0)) ==
            (cnt[j][1] - (i ? cnt[i - 1][1] : 0)) &&
        (cnt[j][2] - (i ? cnt[i - 1][2] : 0)) ==
            (cnt[j][3] - (i ? cnt[i - 1][3] : 0)))
      ans++;
  }

  cout << ans << endl;
}
