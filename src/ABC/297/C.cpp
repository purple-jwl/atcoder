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
  vector<string> vs(h);
  rep(i, h) cin >> vs[i];

  rep(i, h) rep(j, w - 1) if (vs[i][j] == 'T' && vs[i][j + 1] == 'T') {
    vs[i][j] = 'P';
    vs[i][j + 1] = 'C';
  }

  rep(i, h) cout << vs[i] << endl;
}
