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

  vector<string> vs;
  int idx = 0;
  while (idx < s.size()) {
    string tmp = "";
    tmp += s[idx];
    for (int idx2 = idx + 1;; idx2++) {
      tmp += s[idx2];
      if ('A' <= s[idx2] && s[idx2] <= 'Z') {
        idx = idx2 + 1;
        vs.eb(tmp);
        break;
      }
    }
  }

  vector<pair<string, int>> vp;
  rep(i, vs.size()) {
    string tmp = vs[i];
    tmp[0] = (char)(tmp[0] - 'A' + 'a');
    tmp[tmp.size() - 1] = (char)(tmp[tmp.size() - 1] - 'A' + 'a');
    vp.eb(mp(tmp, i));
  }

  sort(all(vp));

  rep(i, vp.size()) cout << vs[vp[i].S];
  cout << endl;
}
