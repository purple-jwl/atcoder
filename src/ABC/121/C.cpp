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
  int N, M;
  cin >> N >> M;
  vector<pair<int, int>> vp;
  rep (i, N) {
    int a, b;
    cin >> a >> b;
    vp.eb(mp(a, b));
  }
  sort(all(vp));

  ll ans = 0;
  int sum = 0;

  rep (i, N) {
    int m = min(M - sum, vp[i].S);
    ans += 1LL * vp[i].F * m;
    sum += m;
    if (sum == M) break;
  }

  cout << ans << endl;
}
