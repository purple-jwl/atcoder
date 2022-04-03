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
const ll INF = 1LL << 60;
// const ll MOD = 1000000007;

int main() {
  ll n;
  cin >> n;

  ll ans = INF;

  for (ll i = 0; i <= 1000000; i++) {
    ll ok = 1000000;
    ll ng = -1;

    while (abs(ok - ng) > 1) {
      ll mid = (ok + ng) / 2;

      ll v = i * i * i + i * i * mid + i * mid * mid + mid * mid * mid;
      if (v >= n)
        ok = mid;
      else
        ng = mid;
    }

    ans = min(i * i * i + i * i * ok + i * ok * ok + ok * ok * ok, ans);
  }

  cout << ans << endl;
}
