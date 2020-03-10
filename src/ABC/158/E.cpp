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

ll modPow(ll x, ll n, ll mod) {
  ll res = 1;
  while (n) {
    if (n & 1) res = res * x % mod;
    x = x * x % mod;
    n >>= 1;
  }
  return res;
}

int main() {
  int n, p;
  cin >> n >> p;
  string s;
  cin >> s;

  reverse(all(s));

  if (p == 2 || p == 5) {
    ll ans = 0;
    ll cnt = 0;
    rep(i, s.size()) {
      int d = s[i] - '0';
      if (d % p == 0) cnt++;
      ans += cnt;
    }
    cout << ans << endl;
    return 0;
  }

  ll ans = 0;
  ll tmp = 0;
  map<ll, ll> cnt;
  cnt[tmp] = 1;
  rep(i, s.size()) {
    int d = s[i] - '0';
    tmp = (tmp + modPow(10, i, p) * d) % p;
    ans += cnt[tmp];
    cnt[tmp]++;
  }

  cout << ans << endl;
}
