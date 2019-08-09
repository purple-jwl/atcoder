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
  int n, q;
  cin >> n >> q;
  vector<pair<int, pii>> vp;
  rep(i, n) {
    int s, t, x;
    cin >> s >> t >> x;
    vp.eb(mp(s - x, mp(1, x)));
    vp.eb(mp(t - x, mp(-1, x)));
  }

  sort(all(vp));
  set<int> si;
  int idx = 0;
  rep(i, q) {
    int d;
    cin >> d;
    while (idx < vp.size() && vp[idx].F <= d) {
      if (vp[idx].S.F == 1)
        si.insert(vp[idx].S.S);
      else
        si.erase(vp[idx].S.S);
      idx++;
    }
    if (si.size() == 0)
      cout << "-1" << endl;
    else
      cout << *(si.begin()) << endl;
  }
}
