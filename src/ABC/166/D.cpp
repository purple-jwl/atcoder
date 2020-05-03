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
  ll x;
  cin >> x;

  for (ll a = 0;; a++) {
    ll v = a * a * a * a * a - x;

    if (v >= 0) {
      for (ll b = 0; b * b * b * b * b <= v; b++) {
        if (b * b * b * b * b == v) {
          cout << a << ' ' << b << endl;
          return 0;
        }
      }
    } else {
      for (ll b = 0; b * b * b * b * b >= v; b--) {
        if (b * b * b * b * b == v) {
          cout << a << ' ' << b << endl;
          return 0;
        }
      }
    }
  }
}
