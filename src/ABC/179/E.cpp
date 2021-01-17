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
  ll N, X, M;
  cin >> N >> X >> M;

  ll ans = 0;
  vector<int> memo(M + 1, -1);
  ll x = X;

  for (ll i = 0; i < N; i++) {
    if (memo[x] != -1) {
      int l = memo[x];
      int r = i;

      int d = r - l;
      ll n = N - r;
      for (int j = l; j < r; j++) {
        ans += x * ((n / d) + (n % d > (j - l) ? 1 : 0));

        x = x * x % M;
      }

      break;
    }

    memo[x] = i;
    ans += x;

    x = x * x % M;
  }

  cout << ans << endl;
}
