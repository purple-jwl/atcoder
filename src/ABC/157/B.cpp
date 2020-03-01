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
  int a[3][3];
  rep(i, 3) rep(j, 3) cin >> a[i][j];
  int n;
  cin >> n;
  rep(i, n) {
    int b;
    cin >> b;
    rep(j, 3) rep(k, 3) if (a[j][k] == b) a[j][k] = -1;
  }

  bool f = false;
  rep(i, 3) {
    bool tmp = true;
    rep(j, 3) {
      if (a[i][j] != -1) tmp = false;
    }
    if (tmp) f = true;
  }

  rep(i, 3) {
    bool tmp = true;
    rep(j, 3) {
      if (a[j][i] != -1) tmp = false;
    }
    if (tmp) f = true;
  }

  bool tmp = true;
  rep(i, 3) if (a[i][i] != -1) tmp = false;
  if (tmp) f = true;

  tmp = true;
  rep(i, 3) if (a[2 - i][i] != -1) tmp = false;
  if (tmp) f = true;

  cout << (f ? "Yes" : "No") << endl;
}
