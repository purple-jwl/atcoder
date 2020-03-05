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
  int n, k;
  cin >> n >> k;

  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  vector<ll> sum(n + 1, 0);
  rep(i, n) sum[i + 1] = a[i] + sum[i];

  ll ans = 0;
  map<int, int> cnt;
  rep(i, n + 1) {
    if (i >= k) cnt[(sum[i - k] - (i - k) + k) % k]--;
    ans += cnt[(sum[i] - i + k) % k];
    cnt[(sum[i] - i + k) % k]++;
  }

  cout << ans << endl;
}
