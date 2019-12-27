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
  ll N, K;
  cin >> N >> K;
  vector<ll> a(N), f(N);
  rep(i, N) cin >> a[i];
  rep(i, N) cin >> f[i];

  sort(all(a));
  sort(rall(f));

  ll ok = 1LL << 60;
  ll ng = -1;

  while (abs(ok - ng) > 1) {
    ll mid = (ok + ng) / 2;

    bool flg = true;
    ll k = K;
    rep(i, N) {
      ll n = ceil((long double)(f[i] * a[i] - mid) / f[i]);
      if (n >= 0) k -= n;
      if (k < 0) flg = false;
    }

    (flg ? ok : ng) = mid;
  }

  cout << ok << endl;
}
