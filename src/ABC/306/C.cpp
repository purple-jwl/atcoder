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
  vector<vector<int>> v(n);
  rep(i, 3 * n) {
    int a;
    cin >> a;
    v[a - 1].emplace_back(i);
  }
  vector<pair<int, int>> vp;
  rep(i, n) vp.emplace_back(make_pair(v[i][1], i + 1));
  sort(all(vp));

  rep(i, n) cout << vp[i].second << ' ';
  cout << endl;
}
