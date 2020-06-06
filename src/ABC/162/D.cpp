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

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  map<char, int> m;
  m['R'] = 0;
  m['G'] = 1;
  m['B'] = 2;

  vector<vector<int>> cnt(3, vector<int>(n, 0));
  rep(i, n) {
    if (i) rep(j, 3) cnt[j][i] = cnt[j][i - 1];
    cnt[m[s[i]]][i]++;
  }

  ll ans = 0;
  REP(i, 0, n) REP(j, i + 1, n) if (s[i] != s[j]) {
    if (j + 1 >= n) break;

    int idx = 3 - m[s[i]] - m[s[j]];
    ans += cnt[idx][n - 1] - cnt[idx][j];

    int k = j + (j - i);
    if (k < n && idx == m[s[k]]) ans--;
  }

  cout << ans << endl;
}
