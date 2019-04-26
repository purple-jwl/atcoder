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
const ll INF = 1LL << 62;
// const int MOD = 1000000007;

int main() {
  int N, K;
  cin >> N >> K;

  vector<pair<int, int>> p;
  rep (i, N) {
    int x, y;
    cin >> x >> y;
    p.eb(mp(x, y));
  }

  sort(all(p));

  ll ans = INF;
  rep (i, N) REP (j, i + 1, N) {
    vector<pair<int, int>> tmp;
    rep (k, N) if (p[i].F <= p[k].F && p[k].F <= p[j].F) tmp.eb(mp(p[k].S, p[k].F));

    ll w = p[j].F - p[i].F;
    sort(all(tmp));

    rep (k, sz(tmp) - K + 1) {
      ll h = tmp[k + K - 1].F - tmp[k].F;
      ans = min(ans, w * h);
    }
  }

  cout << ans << endl;
}
