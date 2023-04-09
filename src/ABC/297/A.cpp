#include <bits/stdc++.h>

#define REP(i, x, n) for (int i = x; i < (int)(n); i++)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define uniq(x) x.erase(unique(x.begin(), x.end()), x.end())

using namespace std;

typedef long long ll;

int main() {
  int n, d;
  cin >> n >> d;
  vector<int> t(n);
  rep(i, n) cin >> t[i];

  rep(i, n - 1) if (t[i + 1] - t[i] <= d) {
    cout << t[i + 1] << endl;
    return 0;
  }
  cout << -1 << endl;
}
