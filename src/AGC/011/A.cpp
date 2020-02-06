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
  int n, c, k;
  cin >> n >> c >> k;
  vector<int> t(n);
  rep(i, n) cin >> t[i];
  sort(all(t));

  int ans = 0;
  int tt = -1;
  int cnt = 0;
  rep(i, n) {
    if (t[i] <= tt && cnt + 1 <= c)
      cnt++;
    else {
      ans++;
      tt = t[i] + k;
      cnt = 1;
    }
  }

  cout << ans << endl;
}
