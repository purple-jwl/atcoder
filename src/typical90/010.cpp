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
  int n;
  cin >> n;
  vector<int> a(n, 0), b(n, 0);
  rep(i, n) {
    int c, p;
    cin >> c >> p;
    if (c == 1)
      a[i] = p;
    else
      b[i] = p;
    if (i > 0) {
      a[i] += a[i - 1];
      b[i] += b[i - 1];
    }
  }

  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    int x = a[r - 1] - (l - 2 < 0 ? 0 : a[l - 2]);
    int y = b[r - 1] - (l - 2 < 0 ? 0 : b[l - 2]);
    cout << x << ' ' << y << endl;
  }
}
