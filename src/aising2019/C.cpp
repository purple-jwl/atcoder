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
  int h, w;
  cin >> h >> w;
  char s[h][w];
  rep(i, h) rep(j, w) cin >> s[i][j];

  ll ans = 0;
  bool visited[h][w];
  memset(visited, 0, sizeof(visited));
  int di[] = {0, 0, 1, -1};
  int dj[] = {1, -1, 0, 0};

  rep(i, h) rep(j, w) if (!visited[i][j]) {
    ll c1 = 0, c2 = 0;
    queue<pii> Q;
    Q.push(mp(i, j));
    visited[i][j] = 1;

    while (!Q.empty()) {
      pii p = Q.front();
      char c = s[p.F][p.S];
      Q.pop();

      if (c == '#')
        c1++;
      else
        c2++;

      rep(k, 4) {
        int ni = p.F + di[k];
        int nj = p.S + dj[k];
        int nc = s[ni][nj];
        if (!(0 <= ni && ni < h)) continue;
        if (!(0 <= nj && nj < w)) continue;
        if (visited[ni][nj]) continue;
        if (nc == c) continue;
        visited[ni][nj] = 1;
        Q.push(mp(ni, nj));
      }
    }

    ans += c1 * c2;
  }

  cout << ans << endl;
}
