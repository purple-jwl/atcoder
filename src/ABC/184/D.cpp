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

double dp[101][101][101];

double f(int a, int b, int c) {
  if (dp[a][b][c] != 0) return dp[a][b][c];
  if (a == 100 || b == 100 || c == 100) return 0;

  double res = 0;
  res += (f(a + 1, b, c) + 1) * a / (a + b + c);
  res += (f(a, b + 1, c) + 1) * b / (a + b + c);
  res += (f(a, b, c + 1) + 1) * c / (a + b + c);

  return dp[a][b][c] = res;
}

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  printf("%.10f\n", f(a, b, c));
}
