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
  int N, T;
  cin >> N >> T;
  vector<int> t(N);
  rep(i, N) cin >> t[i];

  int ans = 0;
  int x = 0, y = 0;
  rep(i, N) {
    if (x <= t[i] && t[i] <= y) {
      ans += T - (y - t[i]);
    } else {
      ans += T;
    }
    x = t[i];
    y = t[i] + T;
  }

  cout << ans << endl;
}
