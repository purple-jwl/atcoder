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
const ll MOD = 1000000007;

const int MAX = 2000005;
ll modFact[MAX];
ll modInv[MAX];
ll modFactInv[MAX];

// calc nCr % mod
ll comb(int n, int r) {
  return modFact[n] * (modFactInv[r] * modFactInv[n - r] % MOD) % MOD;
}

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
  modFact[0] = modFact[1] = 1;
  modFactInv[0] = modFactInv[1] = 1;
  modInv[1] = 1;
  REP(i, 2, MAX) {
    modFact[i] = modFact[i - 1] * i % MOD;
    modInv[i] = MOD - modInv[MOD % i] * (MOD / i) % MOD;
    modFactInv[i] = modFactInv[i - 1] * modInv[i] % MOD;
  }

  ll n, a, b;
  cin >> n >> a >> b;
  ll ans = modPow(2, n, MOD);
  ans = (ans + MOD - 1) % MOD;

  ll x = 1;
  rep(i, a) x = x * (n - i) % MOD;
  rep(i, a) x = x * modInv[(i + 1)] % MOD;

  ll y = 1;
  rep(i, b) y = y * (n - i) % MOD;
  rep(i, b) y = y * modInv[(i + 1)] % MOD;

  ans = (ans + MOD - x) % MOD;
  ans = (ans + MOD - y) % MOD;

  cout << ans << endl;
}
