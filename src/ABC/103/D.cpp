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

bool cmp(pair<int, int> a, pair<int, int> b) {
  if (a.S == b.S) return a.F < b.F;
  return a.S < b.S;
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<pair<int, int>> vp;
  rep (i, m) {
    int a, b;
    cin >> a >> b;
    vp.eb(mp(a, b));
  }

  sort(all(vp), cmp);

  int ans = 0;
  int t = 1;
  rep (i, sz(vp)) {
    if (t <= vp[i].F) {
      ans++;
      t = vp[i].S;
    }
  }

  cout << ans << endl;
}
