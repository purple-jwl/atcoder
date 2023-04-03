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
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  int m;
  cin >> m;
  map<int, int> b;
  rep(i, m) {
    int _b;
    cin >> _b;
    b[_b] = 1;
  }
  int x;
  cin >> x;

  vector<bool> dp(x + 1, 0);
  dp[0] = 1;
  rep(i, x) if (dp[i]) {
    rep(j, n) {
      int next = i + a[j];
      if (next <= x && b[next] != 1) dp[next] = 1;
    }
  }

  cout << (dp[x] ? "Yes" : "No") << endl;
}
