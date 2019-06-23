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

// const int INF = 1 << 29;
// const ll INF = 1LL << 60;
// const int MOD = 1000000007;

ll gcd(ll a, ll b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

ll f(ll a, ll b, ll c) {
  ll d = b / gcd(b, c) * c;

  return a - a / b - a / c + a / d;
}

int main() {
  ll A, B, C, D;
  cin >> A >> B >> C >> D;

  cout << f(B, C, D) - f(A - 1, C, D) << endl;
}
