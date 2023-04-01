#include <bits/stdc++.h>

#define REP(i, x, n) for (int i = x; i < (int)(n); i++)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
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
const int INF = 1 << 29;
// const ll INF = 1LL << 60;
// const ll MOD = 1000000007;

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> edge[n];
  rep(i, m) {
    int u, v;
    cin >> u >> v;
    edge[u - 1].eb(v - 1);
  }

  int ans = -m;
  rep(i, n) {
    queue<int> Q;
    Q.push(i);
    vector<bool> d(n, false);
    d[i] = true;
    while (!Q.empty()) {
      int u = Q.front();
      Q.pop();
      rep(j, edge[u].size()) {
        int v = edge[u][j];
        if (!d[v]) {
          d[v] = true;
          ans++;
          Q.push(v);
        }
      }
    }
  }

  cout << ans << endl;
}
