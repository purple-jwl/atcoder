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

vector<int> idx[26];

int main() {
  string s, t;
  cin >> s;
  cin >> t;
  rep(i, s.size()) { idx[(int)(s[i] - 'a')].eb(i); }
  rep(i, t.size()) {
    if (idx[(int)(t[i] - 'a')].size() == 0) {
      cout << "-1" << endl;
      return 0;
    }
  }

  ll ans = 0;
  int pos = -1;
  int len = s.size();
  rep(i, t.size()) {
    int key = (int)(t[i] - 'a');

    auto it = upper_bound(all(idx[key]), pos);
    int next = -1;

    if (it == idx[key].end()) {
      ans += len;
      pos = -1;
      next = *upper_bound(all(idx[key]), pos);
    } else {
      next = *it;
    }
    pos = next;
  }
  ans += pos + 1;

  cout << ans << endl;
}
