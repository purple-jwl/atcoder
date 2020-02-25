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

int main() {
  modFact[0] = modFact[1] = 1;
  modFactInv[0] = modFactInv[1] = 1;
  modInv[1] = 1;
  REP(i, 2, MAX) {
    modFact[i] = modFact[i - 1] * i % MOD;
    modInv[i] = MOD - modInv[MOD % i] * (MOD / i) % MOD;
    modFactInv[i] = modFactInv[i - 1] * modInv[i] % MOD;
  }

  int n, k;
  cin >> n >> k;

  ll ans = 0;
  rep(i, min(n, k + 1)) {
    ans = (ans + comb(n - 1, n - 1 - i) * comb(n, n - i) % MOD) % MOD;
  }

  cout << ans << endl;
}
