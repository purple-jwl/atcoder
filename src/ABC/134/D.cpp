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

/* --- INFの値が適切か確認する --- */
// const int INF = 1 << 30;
// const ll INF = 1LL << 60;
// const int MOD = 1000000007;

int main() {
  int N;
  cin >> N;
  vector<int> a(N + 1, 0);
  rep(i, N) cin >> a[i + 1];
  vector<int> cnt(N + 1, 0), b(N + 1, 0);

  for (int i = N; i > 0; i--) {
    if (a[i] != (cnt[i] % 2)) {
      b[i] = 1;
      for (int j = 1; j * j <= i; j++) {
        if (i % j == 0) {
          cnt[j]++;
          if (i / j != j) cnt[i / j]++;
        }
      }
    }
  }

  vector<int> ans;
  rep(i, N) if (b[i + 1]) ans.eb(i + 1);

  cout << ans.size() << endl;
  rep(i, ans.size()) {
    if (i != 0) cout << ' ';
    cout << ans[i];
  }
  if (ans.size() > 0) cout << endl;
}
