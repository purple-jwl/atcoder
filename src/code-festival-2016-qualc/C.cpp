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
const ll MOD = 1000000007;

int main() {
  int n;
  cin >> n;
  vector<int> t(n), a(n);
  rep(i, n) cin >> t[i];
  rep(i, n) cin >> a[i];

  vector<int> ht(n, -1), ha(n, -1);
  rep(i, n) if (i == 0 || t[i - 1] != t[i]) ht[i] = t[i];
  for (int i = n - 1; i >= 0; i--)
    if (i == n - 1 || a[i + 1] != a[i]) ha[i] = a[i];

  ll ans = 1;
  rep(i, n) {
    if (ht[i] == -1 && ha[i] == -1) {
      ans = (ans * min(t[i], a[i])) % MOD;
    } else if (ht[i] == -1) {
      if (t[i] < ha[i]) {
        ans = 0;
        break;
      }
    } else if (ha[i] == -1) {
      if (ht[i] > a[i]) {
        ans = 0;
        break;
      }
    } else if (ht[i] != ha[i]) {
      ans = 0;
      break;
    }
  }

  cout << ans << endl;
}
