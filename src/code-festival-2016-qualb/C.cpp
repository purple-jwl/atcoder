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
  int w, h;
  cin >> w >> h;
  vector<pair<ll, char>> vp;
  rep(i, w) {
    int p;
    cin >> p;
    vp.eb(mp(p, 'p'));
  }
  rep(i, h) {
    int q;
    cin >> q;
    vp.eb(mp(q, 'q'));
  }

  sort(all(vp));

  int pcnt = h + 1;
  int qcnt = w + 1;
  ll ans = 0;
  rep(i, vp.size()) {
    if (vp[i].S == 'p') {
      ans += vp[i].F * pcnt;
      qcnt--;
    } else {
      ans += vp[i].F * qcnt;
      pcnt--;
    }
  }

  cout << ans << endl;
}
