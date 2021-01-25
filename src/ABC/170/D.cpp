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
  vector<int> a(n), memo(1000000 + 1, 0);
  rep(i, n) cin >> a[i], memo[a[i]]++;
  sort(all(a));

  int ans = 0;
  rep(i, n) {
    bool f = true;

    for (int j = 1; j * j <= a[i]; j++) {
      if (a[i] % j == 0) {
        int k = a[i] / j;

        if (j != a[i] && memo[j] > 0) f = false;
        if (k != a[i] && memo[k] > 0) f = false;
        if (j == a[i] && memo[j] > 1) f = false;
        if (k == a[i] && memo[k] > 1) f = false;
      }
      if (!f) break;
    }

    if (f) ans++;
  }

  cout << ans << endl;
}
