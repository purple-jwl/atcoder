#include <bits/stdc++.h>

#define REP(i, x, n) for (int i = x; i < (int)(n); i++)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x.size())
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
const int INF = 1 << 30;
// const ll INF = 1LL << 60;
// const ll MOD = 1000000007;

vector<int> edge[100000];
int acost[100000];
int tcost[100000];

void dfs1(int pos) {
  rep(i, edge[pos].size()) {
    int next = edge[pos][i];
    if (tcost[next] == INF) {
      tcost[next] = tcost[pos] + 1;
      dfs1(next);
    }
  }
}

void dfs2(int pos) {
  rep(i, edge[pos].size()) {
    int next = edge[pos][i];
    if (acost[next] == INF) {
      acost[next] = acost[pos] + 1;
      dfs2(next);
    }
  }
}

int main() {
  int n, u, v;
  cin >> n >> u >> v;
  u--;
  v--;
  rep(i, n - 1) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    edge[a].eb(b);
    edge[b].eb(a);
  }

  rep(i, n) acost[i] = tcost[i] = INF;

  tcost[u] = acost[v] = 0;
  dfs1(u);
  dfs2(v);

  int ans = -1;
  //  rep(i, n) cout << tcost[i] << ' ' << acost[i] << endl;
  rep(i, n) {
    if (edge[i].size() > 1) continue;
    if (tcost[i] > acost[i]) continue;
    int bef = edge[i][0];
    ans = max(ans, acost[bef]);
  }

  cout << ans << endl;
}
