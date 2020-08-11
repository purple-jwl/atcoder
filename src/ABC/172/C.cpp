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
  ll n, m, k;
  cin >> n >> m >> k;
  vector<ll> asum(n, 0), bsum(m, 0);
  rep(i, n) {
    int a;
    cin >> a;
    if (i) asum[i] = asum[i - 1];
    asum[i] += a;
  }
  rep(i, m) {
    int b;
    cin >> b;
    if (i) bsum[i] = bsum[i - 1];
    bsum[i] += b;
  }

  int ans = upper_bound(all(bsum), k) - bsum.begin();

  rep(i, n) {
    ll v = k - asum[i];
    if (v < 0) break;
    ans = max(ans, i + 1 + (int)(upper_bound(all(bsum), v) - bsum.begin()));
  }

  cout << ans << endl;
}
