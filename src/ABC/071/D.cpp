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
const int MOD = 1000000007;

int main() {
  int n;
  cin >> n;
  string s1, s2;
  cin >> s1 >> s2;

  ll ans = 1;
  rep (i, n) {
    if (s1[i] == s2[i]) {
      if (i == 0) {
        ans = 3;
      } else if (s1[i - 1] == s2[i - 1]) {
        ans = ans * 2 % MOD;
      }
    } else {
      if (i == 0) {
        ans = 6;
      } else if (s1[i - 1] == s2[i - 1]) {
        ans = ans * 2 % MOD;
      } else {
        ans = ans * 3 % MOD;
      }
      i++;
    }
  }

  cout << ans << endl;
}
