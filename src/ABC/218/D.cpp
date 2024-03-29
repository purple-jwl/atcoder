#include <bits/stdc++.h>

#define REP(i, x, n) for (int i = x; i < (int)(n); i++)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
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

  sort(all(vp));

  map<pii, int> cnt;

  rep(i, n) REP(j, i + 1, n) if (vp[i].F == vp[j].F) cnt[mp(vp[i].S, vp[j].S)]++;

  ll ans = 0;
  for (auto it = cnt.begin(); it != cnt.end(); it++) ans += (it->S - 1) * it->S / 2;

  cout << ans << endl;
}
