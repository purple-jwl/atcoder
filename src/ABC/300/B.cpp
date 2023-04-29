#include <bits/stdc++.h>

#define REP(i, x, n) for (int i = x; i < (int)(n); i++)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define uniq(x) x.erase(unique(x.begin(), x.end()), x.end())

using namespace std;

typedef long long ll;

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> a(h), b(h);
  rep(i, h) cin >> a[i];
  rep(i, h) cin >> b[i];

  rep(s, h) rep(t, w) {
    bool f = true;
    rep(i, h) rep(j, w) {
      if (a[(i + s) % h][(j + t) % w] != b[i][j]) f = false;
    }
    if (f) {
      cout << "Yes" << endl;
      return 0;
    }
  }

  cout << "No" << endl;
}
