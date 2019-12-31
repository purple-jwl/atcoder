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
  vector<vector<int>> table(101, vector<int>(101, 0));
  int n, q;
  cin >> n >> q;
  rep(i, q) {
    int op;
    cin >> op;
    if (op == 1) {
      int a, b;
      cin >> a >> b;
      table[a][b] = 1;
    }
    if (op == 2) {
      int a;
      cin >> a;
      rep(i, n) {
        if (table[i + 1][a]) table[a][i + 1] = 1;
      }
    }
    if (op == 3) {
      int a;
      cin >> a;
      vector<vector<int>> _table = table;
      rep(x, n) if (_table[a][x + 1]) {
        rep(i, n) if (_table[x + 1][i + 1] && (i + 1 != a)) table[a][i + 1] = 1;
      }
    }
  }

  rep(i, n) {
    rep(j, n) cout << (table[i + 1][j + 1] ? "Y" : "N");
    cout << endl;
  }
}
