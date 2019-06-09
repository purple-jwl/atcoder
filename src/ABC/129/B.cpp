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
// const ll INF = 1LL << 60;
// const int MOD = 1000000007;

int main() {
  int n;
  cin >> n;

  vector<int> w(n);
  rep (i, n) cin >> w[i];

  int ans = INF;
  rep (i, n + 1) {
    int a = 0;
    int b = 0;
    for (int j = 0; j < i; j++) a += w[j];
    for (int j = i; j < n; j++) b += w[j];
    ans = min(ans, abs(a - b));
  }

  cout << ans << endl;
}
