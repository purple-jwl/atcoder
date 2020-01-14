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

bool flg[100][100];
char a[100][100];

int main() {
  int h, w;
  cin >> h >> w;
  rep(i, h) rep(j, w) cin >> a[i][j];

  rep(i, h) {
    bool f = true;
    rep(j, w) if (a[i][j] == '#') f = false;
    if (f) rep(j, w) flg[i][j] = true;
  }
  rep(j, w) {
    bool f = true;
    rep(i, h) if (a[i][j] == '#') f = false;
    if (f) rep(i, h) flg[i][j] = true;
  }

  rep(i, h) {
    bool f = true;
    rep(j, w) if (!flg[i][j]) f = false;
    if (!f) {
      rep(j, w) if (!flg[i][j]) cout << a[i][j];
      cout << endl;
    }
  }
}
