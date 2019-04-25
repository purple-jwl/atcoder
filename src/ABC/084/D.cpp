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
  bool isPrime[100000 + 1];
  memset(isPrime, false, sizeof(isPrime));
  REP (i, 2, 100000 + 1) {
    bool flg = true;
    for (int j = 2; j * j <= i; j++) if (i % j == 0) {
      flg = false;
      break;
    }
    if (flg) isPrime[i] = true;
  }

  int sum[100000 + 1];
  memset(sum, 0, sizeof(sum));
  REP (i, 1, 100000 + 1) {
    sum[i] = sum[i - 1] + ((isPrime[i] && isPrime[(i + 1) / 2]) ? 1 : 0);
  }

  int Q;
  cin >> Q;

  rep (i, Q) {
    int l, r;
    cin >> l >> r;
    cout << sum[r] - sum[l - 1] << endl;
  }
}
