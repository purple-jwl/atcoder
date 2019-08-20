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
const ll MOD = 1000000007;

int main() {
  int n, m;
  cin >> n >> m;
  ll xsum = 0, ysum = 0;
  rep(i, n) {
    ll x;
    cin >> x;
    xsum += x * (2 * i - n + 1);
    xsum %= MOD;
  }
  rep(i, m) {
    ll y;
    cin >> y;
    ysum += y * (2 * i - m + 1);
    ysum %= MOD;
  }
  cout << xsum * ysum % MOD << endl;
}
