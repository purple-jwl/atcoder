#include <bits/stdc++.h>

#define REP(i, x, n) for (int i = x; i < (int)(n); i++)
#define rep(i, n) REP (i, 0, n)
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

using namespace std;

typedef long long ll;

const int INF = 1 << 30;

int main() {
  int ans = 0;
  vector<int> tmp;
  rep (i, 5) {
    int x;
    cin >> x;
    ans += x - x % 10;
    if (x % 10) tmp.eb(x % 10);
  }

  sort(all(tmp));

  rep (i, sz(tmp)) {
    if (i == 0) ans += tmp[i];
    else ans += 10;
  }

  cout << ans << endl;
}
