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

  vector<int> idx(26, -1);
  rep(i, s.size()) idx[(int)(s[i] - 'a')] = i;

  if (s.size() != 26) {
    rep(i, 26) if (idx[i] == -1) {
      s += (char)('a' + i);
      cout << s << endl;
      return 0;
    }
  } else {
    for (int i = 25; i >= 0; i--) {
      REP(k, 1, 26) {
        int ii = (int)(s[i] - 'a' + k);
        if (ii >= 26) break;
        if (i < idx[ii]) {
          cout << s.substr(0, i) + (char)('a' + ii) << endl;
          return 0;
        }
      }
    }
  }

  cout << "-1" << endl;
}
