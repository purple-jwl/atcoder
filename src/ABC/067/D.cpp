#include <bits/stdc++.h>

#define REP(i, x, n) for (int i = x; i < (int)(n); i++)
#define rep(i, n) REP (i, 0, n)
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

using namespace std;

typedef long long ll;

const int INF = 1 << 30;
// const ll INF = 1LL << 60;
// const int MOD = 1000000007;

vector<int> edge[100000];
int board[100000];

int dfs1(int cur, int prev, int target, int dist) {
  if (cur == target) return dist;

  int res = -1;

  rep (i, edge[cur].size()) {
    int next = edge[cur][i];
    if (next == prev) continue;
    res = max(res, dfs1(next, cur, target, dist + 1));
  }

  return res;
}

void dfs2(int cur, int prev, int color, int dist, int limit) {
  if (dist >= limit) return;

  rep (i, edge[cur].size()) {
    int next = edge[cur][i];
    if (next == prev) continue;
    if (board[next] != 0 && board[next] != color) continue;
    board[next] = color;
    dfs2(next, cur, color, dist + 1, limit);
  }
}

int main() {
  int N;
  cin >> N;
  rep (i, N - 1) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    edge[a].eb(b);
    edge[b].eb(a);
  }

  int dist = dfs1(0, 0, N - 1, 0);

  board[0] = 1;
  board[N - 1] = 2;
  dfs2(    0,     0, 1, 0, dist / 2);
  dfs2(N - 1, N - 1, 2, 0, dist / 2);
  dfs2(    0,     0, 1, 0, INF);
  dfs2(N - 1, N - 1, 2, 0, INF);

  int cnt1 = 0, cnt2 = 0;
  rep (i, N) {
    if (board[i] == 1) cnt1++;
    if (board[i] == 2) cnt2++;
  }

  cout << (cnt1 > cnt2 ? "Fennec" : "Snuke") << endl;
}
