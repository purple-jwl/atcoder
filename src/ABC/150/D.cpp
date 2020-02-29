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
  ll n, m;
  cin >> n >> m;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  set<ll> si;
  rep(i, n) {
    int cnt = 0;
    ll tmp = a[i];
    while (tmp % 2 == 0) {
      tmp /= 2;
      cnt++;
    }
    si.insert(cnt);
  }

  if (si.size() != 1) {
    cout << 0 << endl;
    return 0;
  }

  ll lcm = 1;
  rep(i, n) {
    ll g = __gcd(lcm, a[i] / 2);
    lcm = lcm * a[i] / 2 / g;
    if (lcm > m) {
      cout << 0 << endl;
      return 0;
    }
  }

  cout << (m / lcm + 1) / 2 << endl;
}
