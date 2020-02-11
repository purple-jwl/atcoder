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
  ll k;
  cin >> k;

  ll ans = 0;

  if (s[0] != s[s.size() - 1]) {
    rep(i, s.size()) {
      int j = i;
      while (j + 1 < s.size() && s[i] == s[j + 1]) j++;
      ans += (j - i + 1) / 2;
      i = j;
    }
    ans *= k;
  } else {
    int l = 0;
    int r = 0;
    while (l < s.size() && s[0] == s[l]) l++;
    while (r < s.size() && s[s.size() - 1] == s[s.size() - 1 - r]) r++;
    if (l == s.size()) {
      ans = k * s.size() / 2;
    } else {
      rep(i, s.size()) {
        int j = i;
        while (j + 1 < s.size() && s[i] == s[j + 1]) j++;
        ans += (j - i + 1) / 2;
        i = j;
      }
      ans *= k;
      if (l % 2 && r % 2) ans += (k - 1);
    }
  }

  cout << ans << endl;
}
