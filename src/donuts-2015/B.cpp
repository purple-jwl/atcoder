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
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  vector<int> b(m);
  vector<vector<int>> I(m);
  rep(i, m) {
    int c;
    cin >> b[i] >> c;
    rep(j, c) {
      int _i;
      cin >> _i;
      I[i].eb(_i - 1);
    }
  }

  int ans = 0;
  rep(i, (1 << n)) {
    if (popcount(i) != 9) continue;

    int sum = 0;

    rep(j, n) if ((i >> j) & 1) sum += a[j];

    rep(j, m) {
      int cnt = 0;
      rep(k, I[j].size()) if ((i >> I[j][k]) & 1) cnt++;
      if (cnt >= 3) sum += b[j];
    }

    ans = max(ans, sum);
  }
  cout << ans << endl;
}
