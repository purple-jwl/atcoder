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

const int INF = 1 << 29;
// const ll INF = 1LL << 60;
// const int MOD = 1000000007;

int main() {
  int N, L;
  cin >> N >> L;

  int ans = 0;
  int diff = INF;
  int a = 0;
  rep (i, N) a += i + L;

  rep (i, N) {
    int b = 0;
    rep (j, N) if (i != j) b += j + L;
    if (diff > abs(a - b)) {
      diff = abs(a - b);
      ans = b;
    }
  }

  cout << ans << endl;
}
