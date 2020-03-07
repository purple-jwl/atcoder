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
  string s;
  cin >> s;
  int q;
  cin >> q;
  bool a = true;

  vector<char> fr, bk;

  rep(_, q) {
    int op;
    cin >> op;
    if (op == 1) {
      a = !a;
    } else {
      int f;
      char c;
      cin >> f >> c;
      if (f == 1) {
        if (a)
          fr.eb(c);
        else
          bk.eb(c);
      } else {
        if (a)
          bk.eb(c);
        else
          fr.eb(c);
      }
    }
  }

  if (a) {
    reverse(all(fr));
    rep(i, fr.size()) cout << fr[i];
    cout << s;
    rep(i, bk.size()) cout << bk[i];
    cout << endl;
  } else {
    reverse(all(bk));
    reverse(all(s));
    rep(i, bk.size()) cout << bk[i];
    cout << s;
    rep(i, fr.size()) cout << fr[i];
    cout << endl;
  }
}
