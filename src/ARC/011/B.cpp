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
  int n;
  cin >> n;
  vector<string> ans;
  rep(i, n) {
    string w;
    cin >> w;

    string _w = "";
    rep(j, w.size()) {
      char c = w[j];
      if ('A' <= c && c <= 'Z') c = (char)('a' + c - 'A');
      if (c == 'b' || c == 'c') _w += '1';
      if (c == 'd' || c == 'w') _w += '2';
      if (c == 't' || c == 'j') _w += '3';
      if (c == 'f' || c == 'q') _w += '4';
      if (c == 'l' || c == 'v') _w += '5';
      if (c == 's' || c == 'x') _w += '6';
      if (c == 'p' || c == 'm') _w += '7';
      if (c == 'h' || c == 'k') _w += '8';
      if (c == 'n' || c == 'g') _w += '9';
      if (c == 'z' || c == 'r') _w += '0';
    }

    if (_w.size() > 0) ans.eb(_w);
  }
  rep(i, ans.size()) {
    if (i) cout << ' ';
    cout << ans[i];
  }
  cout << endl;
}
