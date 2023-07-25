#include <bits/stdc++.h>

#define REP(i, x, n) for (int i = x; i < (int)(n); i++)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define uniq(x) x.erase(unique(x.begin(), x.end()), x.end())

using namespace std;

typedef long long ll;

int main() {
  int n;
  cin >> n;
  vector<double> x(n), y(n);
  rep(i, n) cin >> x[i] >> y[i];

  double ans = 0;
  rep(i, n) REP(j, i + 1, n) {
    double dx = x[i] - x[j];
    double dy = y[i] - y[j];
    ans = max(ans, sqrt(dx * dx + dy * dy));
  }

  printf("%.10f\n", ans);
}
