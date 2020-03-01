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
  vector<vector<int>> d(n, vector<int>());
  rep(i, m) {
    int s, c;
    cin >> s >> c;
    d[s - 1].eb(c);
  }

  int ans = 0;
  if (n == 1) {
    rep(i, n) {
      vector<int> a = d[i];
      uniq(a);
      if (a.size() > 1) {
        ans = -1;
        break;
      }

      if (a.size() != 0) ans = a[i];
    }
  } else {
    rep(i, n) {
      vector<int> a = d[i];
      uniq(a);
      if (a.size() > 1) {
        ans = -1;
        break;
      }

      if (a.size() == 0) {
        if (ans == 0)
          ans = 1;
        else
          ans *= 10;
      } else {
        if (ans == 0 && a[0] == 0) {
          ans = -1;
          break;
        }
        ans = 10 * ans + a[0];
      }
    }
  }

  cout << ans << endl;
}
