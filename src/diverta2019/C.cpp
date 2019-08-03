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
  int n;
  cin >> n;
  int ans = 0;
  int ba = 0, a = 0, b = 0;
  rep(i, n) {
    string s;
    cin >> s;

    rep(j, sz(s) - 1) if (s[j] == 'A' && s[j + 1] == 'B') ans++;

    if (s[0] == 'B' && s[sz(s) - 1] == 'A')
      ba++;
    else if (s[0] == 'B')
      b++;
    else if (s[sz(s) - 1] == 'A')
      a++;
  }
  if (ba > 0) {
    ans += ba - 1;
    if (a > 0) {
      ans++;
      a--;
    }
    if (b > 0) {
      ans++;
      b--;
    }
  }
  ans += min(a, b);
  cout << ans << endl;
}
