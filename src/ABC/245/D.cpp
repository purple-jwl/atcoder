#include <bits/stdc++.h>

#define REP(i, x, n) for (int i = x; i < (int)(n); i++)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
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
  int n, m;
  cin >> n >> m;
  vector<int> a(n + 1), c(n + m + 1);
  rep(i, n + 1) cin >> a[i];
  rep(i, n + m + 1) cin >> c[i];

  vector<int> b(m + 1);

  for (int i = m; i >= 0; i--) {
    b[i] = c[i + n] / a[n];
    rep(j, n + 1) c[i + j] -= b[i] * a[j];
  }

  rep(i, m + 1) cout << b[i] << ' ';
  cout << endl;
}
