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
// const int INF = 1 << 30;
// const ll INF = 1LL << 60;
// const ll MOD = 1000000007;

vector<pii> edge[100000];
int p[100000];
bool visited[100000];

void dfs(int cur, int prev, int n) {
  rep(i, edge[cur].size()) {
    pii e = edge[cur][i];
    if (e.F == prev) continue;
    if (visited[e.F]) continue;
    visited[e.F] = 1;

    if (p[cur] == e.S)
      p[e.F] = (e.S + 1) % n;
    else
      p[e.F] = e.S;

    dfs(e.F, cur, n);
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  set<int> st;
  rep(i, m) {
    int u, v, c;
    cin >> u >> v >> c;
    u--;
    v--;
    c--;
    st.insert(u);
    st.insert(v);

    edge[u].eb(mp(v, c));
    edge[v].eb(mp(u, c));
  }

  if (st.size() != n) {
    cout << "No" << endl;
    return 0;
  }

  p[0] = 0;
  visited[0] = 1;
  dfs(0, -1, n);

  rep(i, n) cout << p[i] + 1 << endl;
}
