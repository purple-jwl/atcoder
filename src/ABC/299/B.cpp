#include <bits/stdc++.h>

#define REP(i, x, n) for (int i = x; i < (int)(n); i++)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define uniq(x) x.erase(unique(x.begin(), x.end()), x.end())

using namespace std;

typedef long long ll;

int main() {
  int n, t;
  cin >> n >> t;
  map<int, int> mx, mi;
  vector<int> c(n), r(n);
  rep(i, n) cin >> c[i];
  rep(i, n) cin >> r[i];
  rep(i, n) if (mx[c[i]] < r[i]) {
    mx[c[i]] = r[i];
    mi[c[i]] = i + 1;
  }

  if (mx[t] > 0)
    cout << mi[t] << endl;
  else
    cout << mi[c[0]] << endl;
}
