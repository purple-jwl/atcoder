#include <bits/stdc++.h>

#define REP(i, x, n) for (int i = x; i < (int)(n); i++)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define uniq(x) x.erase(unique(x.begin(), x.end()), x.end())

using namespace std;

typedef long long ll;

const ll MAX = 1e18;

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<ll>> edge(n, vector<ll>(n, MAX));
  rep(i, n) edge[i][i] = 0;

  vector<int> v(n);
  rep(i, n) v[i] = i;

  rep(i, m) {
    int a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    edge[a][b] = edge[b][a] = c;
  }

  ll ans = 0;
  do {
    ll sum = 0;
    rep(i, n - 1) {
      if (edge[v[i]][v[i + 1]] == MAX) {
        sum = -1;
        break;
      }
      sum += edge[v[i]][v[i + 1]];
      ans = max(ans, sum);
    }
  } while (next_permutation(all(v)));

  cout << ans << endl;
}
