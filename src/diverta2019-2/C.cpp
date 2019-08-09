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
  int n;
  cin >> n;
  multiset<int> pos, neg;
  rep(i, n) {
    int a;
    cin >> a;
    if (a >= 0)
      pos.insert(a);
    else
      neg.insert(a * -1);
  }

  vector<pii> vp;
  rep(i, n - 1) {
    int x, y;
    if (pos.size() == 0) {
      x = *neg.begin();
      neg.erase(neg.begin());
      y = *neg.begin();
      neg.erase(neg.begin());
      vp.eb(mp(x * -1, y * -1));
      pos.insert(y - x);
    } else if (neg.size() == 0) {
      x = *pos.begin();
      pos.erase(pos.begin());
      y = *pos.begin();
      pos.erase(pos.begin());
      vp.eb(mp(x, y));
      neg.insert(y - x);
    } else {
      x = *pos.begin();
      pos.erase(pos.begin());
      y = *neg.begin();
      neg.erase(neg.begin());

      if (pos.size() > neg.size()) {
        vp.eb(mp(y * -1, x));
        neg.insert(x + y);
      } else {
        vp.eb(mp(x, y * -1));
        pos.insert(x + y);
      }
    }
  }

  int ans = pos.size() == 0 ? *neg.begin() : *pos.begin();
  cout << ans << endl;
  rep(i, vp.size()) cout << vp[i].F << ' ' << vp[i].S << endl;
}
