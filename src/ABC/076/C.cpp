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
  string s, t;
  cin >> s >> t;

  reverse(all(s));
  reverse(all(t));

  rep(i, s.size() - t.size() + 1) {
    bool f = true;
    rep(j, t.size()) if (s[i + j] != '?' && s[i + j] != t[j]) f = false;

    if (f) {
      string ans = "";
      rep(j, i) ans += s[j];
      ans += t;
      REP(j, i + t.size(), s.size()) ans += s[j];
      reverse(all(ans));
      rep(j, ans.size()) if (ans[j] == '?') ans[j] = 'a';
      cout << ans << endl;
      return 0;
    }
  }

  cout << "UNRESTORABLE" << endl;
}
