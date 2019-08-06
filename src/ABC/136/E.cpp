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
// const int MOD = 1000000007;

int main() {
  ll N, K;
  cin >> N >> K;
  vector<int> A(N);
  rep(i, N) cin >> A[i];

  int sum = 0;
  rep(i, N) sum += A[i];

  vector<int> d;
  for (int i = 1; i * i <= sum; i++) {
    if (sum % i == 0) {
      d.eb(i);
      if (sum / i != i) {
        d.eb(sum / i);
      }
    }
  }

  sort(rall(d));

  rep(i, sz(d)) {
    int mod = d[i];
    vector<int> a = A;
    rep(j, sz(a)) a[j] %= mod;

    sort(all(a));
    ll m = 0, p = 0;
    rep(j, sz(a)) p += (mod - a[j]);

    rep(j, sz(a)) {
      m += a[j];
      p -= (mod - a[j]);
      if (m == p && m <= K) {
        cout << mod << endl;
        return 0;
      }
    }
  }

  cout << "-1" << endl;
}
