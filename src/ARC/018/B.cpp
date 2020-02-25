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
  int n;
  cin >> n;
  vector<pii> vp(n);
  rep(i, n) cin >> vp[i].F >> vp[i].S;

  int ans = 0;
  rep(i, n) REP(j, i + 1, n) REP(k, j + 1, n) {
    ll x1 = vp[i].F - vp[j].F;
    ll y1 = vp[i].S - vp[j].S;
    ll x2 = vp[i].F - vp[k].F;
    ll y2 = vp[i].S - vp[k].S;
    ll tmp = abs(x1 * y2 - x2 * y1);
    if (tmp != 0 && tmp % 2 == 0) ans++;
  }

  cout << ans << endl;
}
