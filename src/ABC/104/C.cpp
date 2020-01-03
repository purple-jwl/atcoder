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
  int D, G;
  cin >> D >> G;
  vector<int> p(D), c(D);
  rep(i, D) cin >> p[i] >> c[i];

  int ans = 10000000;
  rep(i, (1 << D)) {
    int sum = 0;
    int cnt = 0;
    vector<int> vi;
    rep(j, D) {
      if ((i >> j) & 1) {
        sum += c[j] + p[j] * 100 * (j + 1);
        cnt += p[j];
      } else {
        rep(k, p[j]) vi.eb(100 * (j + 1));
      }
    }
    sort(rall(vi));
    rep(j, vi.size()) {
      if (sum >= G) break;
      sum += vi[j];
      cnt++;
    }
    ans = min(ans, cnt);
  }

  cout << ans << endl;
}
