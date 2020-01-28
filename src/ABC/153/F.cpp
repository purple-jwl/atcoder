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
  ll N, D, A;
  cin >> N >> D >> A;
  vector<pll> xh(N);
  rep(i, N) cin >> xh[i].F >> xh[i].S;

  sort(all(xh));

  ll ans = 0;

  ll b = 0;
  queue<pll> minus;

  rep(i, N) {
    int x = xh[i].F;
    int h = xh[i].S;

    while (!minus.empty()) {
      if (x >= minus.front().S) {
        b -= minus.front().F;
        minus.pop();
      } else {
        break;
      }
    }

    if (h <= b) {
      //
    } else {
      ll cnt = (h - b) / A + ((h - b) % A ? 1 : 0);
      ans += cnt;
      b += A * cnt;
      minus.push(mp(A * cnt, x + 2 * D + 1));
    }
  }

  cout << ans << endl;
}
