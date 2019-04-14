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

// const int INF = 1 << 30;
// const ll INF = 1LL << 60;
// const int MOD = 1000000007;

int main() {
  int N, K;
  string S;
  cin >> N >> K;
  cin >> S;

  vector<pair<char, int>> vp;
  int cnt = 0;
  rep (i, N) {
    cnt++;
    if (i + 1 == N || S[i] != S[i + 1]) {
      vp.eb(mp(S[i], cnt));
      cnt = 0;
    }
  }

  int ans = 0;
  int sum = 0;
  int kCnt = 0;
  int pos = 0;
  rep (i, sz(vp)) {
    sum += vp[i].S;
    if (vp[i].F == '0') kCnt++;
    while (kCnt > K && pos <= i) {
      sum -= vp[pos].S;
      if (vp[pos].F == '0') kCnt--;
      pos++;
    }
    ans = max(ans, sum);
  }

  cout << ans << endl;
}
