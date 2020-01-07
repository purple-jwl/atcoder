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

int f(int x, int y, int z, string s) {
  int idx = 0;

  for (; idx < s.size(); idx++) {
    if ((int)(s[idx] - '0') == x) break;
  }
  if (idx++ == s.size()) return 0;

  for (; idx < s.size(); idx++) {
    if ((int)(s[idx] - '0') == y) break;
  }
  if (idx++ == s.size()) return 0;

  for (; idx < s.size(); idx++) {
    if ((int)(s[idx] - '0') == z) break;
  }
  if (idx++ == s.size()) return 0;

  return 1;
}

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  int ans = 0;
  rep(i, 10) rep(j, 10) rep(k, 10) ans += f(i, j, k, s);

  cout << ans << endl;
}
