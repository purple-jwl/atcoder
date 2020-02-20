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
  int o = 0, e = 0;
  vector<int> x(3);
  rep(i, 3) {
    cin >> x[i];
    if (x[i] % 2)
      o++;
    else
      e++;
  }

  int ans = 0;

  if (o == 2) {
    rep(i, 3) if (x[i] % 2) x[i]++;
    ans++;
  } else if (e == 2) {
    rep(i, 3) if (x[i] % 2 == 0) x[i]++;
    ans++;
  }

  sort(all(x));
  rep(i, 3) ans += (x[2] - x[i]) / 2;

  cout << ans << endl;
}
