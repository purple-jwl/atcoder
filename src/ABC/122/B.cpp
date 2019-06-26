#include <bits/stdc++.h>

#define REP(i, x, n) for (int i = x; i < (int)(n); i++)
#define rep(i, n) REP (i, 0, n)
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

using namespace std;

typedef long long ll;

// const int INF = 1 << 30;
// const ll INF = 1LL << 60;
// const int MOD = 1000000007;

int main() {
  string s;
  cin >> s;
  int ans = 0;
  for (int i = 0; i <= s.size(); i++) {
    for (int j = i; j <= s.size(); j++) {
      int tmp = 0;
      bool flg = true;
      for (int k = i; k < j; k++) {
        if (s[k] == 'A') tmp++;
        else if (s[k] == 'C') tmp++;
        else if (s[k] == 'G') tmp++;
        else if (s[k] == 'T') tmp++;
        else flg = false;
      }
      if (flg) ans = max(ans, tmp);
    }
  }

  cout << ans << endl;
}
