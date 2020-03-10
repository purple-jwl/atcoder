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
#define PI acos(-1)

using namespace std;

typedef long long ll;

/* --- INFやMODの値が適切か確認する --- */
// const int INF = 1 << 30;
// const ll INF = 1LL << 60;
// const ll MOD = 1000000007;

int main() {
  double a, b, x;
  cin >> a >> b >> x;

  double ans;
  // 台形
  if (2 * x >= a * a * b) {
    ans = atan(2 * (a * a * b - x) / (a * a * a)) * 180 / PI;
  } else {
    ans = atan(a * b * b / (2 * x)) * 180 / PI;
  }

  printf("%.10f\n", ans);
}
