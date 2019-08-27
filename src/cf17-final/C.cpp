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

int N;
int D[13];

int rec(int idx, vector<int> v) {
  int res = 100000000;

  if (idx > 12) {
    sort(all(v));
    rep(i, v.size()) {
      int d = abs(v[(i + 1) % v.size()] - v[i]);
      res = min({res, d, 24 - d});
    }
  } else {
    if (D[idx] > 2) {
      return 0;
    } else if (D[idx] == 2) {
      v.eb(idx);
      v.eb((24 - idx) % 24);
      res = rec(idx + 1, v);
    } else if (D[idx] == 1) {
      vector<int> v1 = v, v2 = v;
      v1.eb(idx);
      v2.eb((24 - idx) % 24);
      res = max(rec(idx + 1, v1), rec(idx + 1, v2));
    } else {
      res = rec(idx + 1, v);
    }
  }

  return res;
}

int main() {
  cin >> N;
  rep(i, N) {
    int d;
    cin >> d;
    D[d]++;
  }
  D[0]++;
  cout << rec(0, vector<int>()) << endl;
}
