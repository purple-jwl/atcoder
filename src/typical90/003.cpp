#include <bits/stdc++.h>

#define REP(i, x, n) for (int i = x; i < (int)(n); i++)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
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

int n;
vector<int> edge[100000];

int bfs() {
  queue<int> Q;
  vector<bool> visited(n, false);

  Q.push(0);
  visited[0] = true;

  int u = 0;

  while (!Q.empty()) {
    int cur = Q.front();
    Q.pop();

    rep(i, edge[cur].size()) {
      int next = edge[cur][i];
      if (visited[next]) continue;
      visited[next] = true;
      Q.push(next);
      u = next;
    }
  }

  return u;
}

int dfs(int cur, int prev) {
  int res = 0;

  rep(i, edge[cur].size()) {
    int next = edge[cur][i];
    if (prev == next) continue;
    res = max(res, dfs(next, cur) + 1);
  }

  return res;
}

int main() {
  cin >> n;

  rep(i, n - 1) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    edge[a].eb(b);
    edge[b].eb(a);
  }

  int dist = dfs(bfs(), -1);

  cout << dist + 1 << endl;
}
