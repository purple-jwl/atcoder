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
// const int MOD = 1000000007;

int main() {
  int n, a, b, c, d;
  cin >> n >> a >> b >> c >> d;
  string s;
  cin >> s;
  s = "-" + s;

  bool flg = true;
  for (int i = a; i < c; i++) {
    if (s[i] == '#' && s[i + 1] == '#') flg = false;
  }
  for (int i = b; i < d; i++) {
    if (s[i] == '#' && s[i + 1] == '#') flg = false;
  }
  if (c > d) {
    bool flg2 = false;
    for (int i = b; i <= d; i++) {
      if (s[i - 1] == '.' && s[i] == '.' && s[i + 1] == '.') flg2 = true;
    }
    if (flg) flg = flg2;
  }
  cout << (flg ? "Yes" : "No") << endl;
}
