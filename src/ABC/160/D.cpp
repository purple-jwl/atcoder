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
  int n, x, y;
  cin >> n >> x >> y;

  x--;
  y--;

  vector<int> d(n, 0);
  rep(i, n) REP(j, i + 1, n) {
    int tmp = j - i;

    if (i <= x && y <= j) {
      tmp = min(j - i, x - i + 1 + j - y);
    } else if (x <= i && y <= j) {
      tmp = min(j - i, i - x + 1 + j - y);
    } else if (i <= x && j <= y) {
      tmp = min(j - i, x - i + 1 + y - j);
    } else {
      tmp = min(j - i, i - x + 1 + y - j);
    }
    d[tmp]++;
  }

  REP(i, 1, n) cout << d[i] << endl;
}
