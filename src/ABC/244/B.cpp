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
  int x = 0, y = 0, d = 0;
  string t;
  cin >> t;
  int dx[] = {1, 0, -1, 0};
  int dy[] = {0, -1, 0, 1};
  rep(i, t.size()) {
    if (t[i] == 'S') {
      x += dx[d];
      y += dy[d];
    } else
      d = (d + 1) % 4;
  }
  cout << x << ' ' << y << endl;
}
