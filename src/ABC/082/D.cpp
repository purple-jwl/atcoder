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
  string s;
  cin >> s;
  int x, y;
  cin >> x >> y;

  int d = 0;
  bool xflg = true;
  vector<int> xd, yd;
  rep(i, s.size()) {
    if (s[i] == 'F') d++;
    if (s[i] == 'T' || (i == s.size() - 1)) {
      if (xflg)
        xd.eb(d);
      else
        yd.eb(d);
      d = 0;
      xflg = !xflg;
    }
  }

  vector<vector<bool>> xdp(2, vector<bool>(17000, false));
  xdp[0][8000] = true;
  rep(i, xd.size()) {
    int cur = i % 2;
    int next = (i + 1) % 2;
    xdp[next] = vector<bool>(17000, false);
    rep(j, 17000) if (xdp[cur][j]) {
      xdp[next][j + xd[i]] = true;
      if (i) xdp[next][j - xd[i]] = true;
    }
  }

  vector<vector<bool>> ydp(2, vector<bool>(17000, false));
  ydp[0][8000] = true;
  rep(i, yd.size()) {
    int cur = i % 2;
    int next = (i + 1) % 2;
    ydp[next] = vector<bool>(17000, false);
    rep(j, 17000) if (ydp[cur][j]) {
      ydp[next][j + yd[i]] = ydp[next][j - yd[i]] = true;
    }
  }

  if (xdp[xd.size() % 2][x + 8000] && ydp[yd.size() % 2][y + 8000]) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
