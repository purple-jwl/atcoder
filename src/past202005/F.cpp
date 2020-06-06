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

bool flg[500][26];

int main() {
  int n;
  cin >> n;
  rep(i, n) {
    string a;
    cin >> a;
    rep(j, a.size()) flg[i][a[j] - 'a'] = 1;
  }

  string s = "", t = "";
  rep(i, n) {
    int j = n - 1 - i;
    if (i > j) break;

    bool f = false;
    rep(k, 26) if (flg[i][k] && flg[j][k]) {
      s += (char)('a' + k);
      if (i != j) t += (char)('a' + k);
      f = true;
      break;
    }

    if (!f) {
      cout << "-1" << endl;
      return 0;
    }
  }

  reverse(all(t));

  cout << s << t << endl;
}
