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

  int t[n][n];
  rep(i, n) rep(j, n) cin >> t[i][j];

  vector<int> a(n);
  iota(all(a), 0);

  int ans = 0;
  do {
    if (a[0] != 0) continue;
    int c = 0;
    rep(i, n) c += t[a[i]][a[(i + 1) % n]];
    if (c == k) ans++;
  } while (next_permutation(all(a)));

  cout << ans << endl;
}
