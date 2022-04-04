#include <bits/stdc++.h>

#define REP(i, x, n) for (int i = x; i < (int)(n); i++)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
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
  int T, Q;
  double L, X, Y;
  cin >> T >> L >> X >> Y >> Q;

  while (Q--) {
    int E;
    cin >> E;

    double x = 0;
    double y = L / -2 * sin(M_PI / 180 * 360 * E / T);
    double z = L / 2 - L / 2 * cos(M_PI / 180 * 360 * E / T);
    double ans = atan2(z, sqrt(pow(X - x, 2) + pow(Y - y, 2))) * 180 / M_PI;

    printf("%.10f\n", ans);
  }
}
