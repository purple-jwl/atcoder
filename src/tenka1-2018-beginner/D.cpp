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
  int n;
  cin >> n;

  for (int k = 1;; k++) {
    int s = k * (k + 1) / 2;
    if (s > n) break;
    if (s == n) {
      cout << "Yes" << endl;
      cout << k + 1 << endl;

      vector<int> ans[k + 1];
      int idx = 0;
      for (int i = k; i >= 1; i--) {
        for (int j = 0; j < i; j++) {
          ans[k - i].eb(j + idx + 1);
          ans[k - i + j + 1].eb(j + idx + 1);
        }
        idx += i;
      }

      rep(i, k + 1) {
        cout << k;
        rep(j, k) cout << ' ' << ans[i][j];
        cout << endl;
      }

      return 0;
    }
  }

  cout << "No" << endl;
}
