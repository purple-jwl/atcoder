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
  int n, m;
  cin >> n >> m;

  vector<vector<int>> s(m);
  rep (i, m) {
    int k;
    cin >> k;
    s[i] = vector<int>(k);
    rep (j, k) cin >> s[i][j];
  }

  vector<int> p(m);
  rep (i, m) cin >> p[i];

  int ans = 0;

  rep (on, (1 << n)) {
    bool flg = true;
    rep (i, m) {
      int sum = 0;
      rep (j, s[i].size()) {
        sum += (on >> (s[i][j] - 1)) & 1;
      }
      if (sum % 2 != p[i]) flg = false;
    }
    ans += flg;
  }

  cout << ans << endl;
}
