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
  string s;
  cin >> s;

  int n = s.size() + 1;
  vector<int> l(n, 0), r(n, 0);

  rep(i, s.size()) {
    if (s[i] == '<') {
      do {
        l[i + 1] = l[i] + 1;
      } while (++i < s.size() && s[i] == '<');
    }
  }

  for (int i = s.size() - 1; i >= 0; i--) {
    if (s[i] == '>') {
      do {
        r[i] = r[i + 1] + 1;
      } while (--i >= 0 && s[i] == '>');
    }
  }

  ll ans = 0;
  rep(i, n) {
    // cout << l[i] << ' ' << r[i] << endl;
    ans += max(l[i], r[i]);
  }

  cout << ans << endl;
}
