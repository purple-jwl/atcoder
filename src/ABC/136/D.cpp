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
  string s;
  cin >> s;
  int n = sz(s);
  vector<int> ans(n, 0);

  int idx = 0;
  while (idx < n) {
    int l = idx;
    int lcnt = 0;
    while (s[l] == 'R') {
      l++;
      lcnt++;
    }
    int r = l;
    int rcnt = 0;
    while (r < n && s[r] == 'L') {
      r++;
      rcnt++;
    }
    ans[l - 1] = (lcnt - 1) / 2 + rcnt / 2 + 1;
    ans[l] = lcnt / 2 + (rcnt - 1) / 2 + 1;
    idx = r;
  }

  rep(i, n) {
    if (i != 0) cout << ' ';
    cout << ans[i];
  }
  cout << endl;
}
