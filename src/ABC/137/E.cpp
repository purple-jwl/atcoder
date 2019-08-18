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

/* --- INFの値が適切か確認する --- */
// const int INF = 1 << 30;
const ll INF = 1LL << 60;
// const int MOD = 1000000007;

vector<pii> edge[2500], redge[2500];
ll d[2500];
bool visited[2500];

int main() {
  int N, M, P;
  cin >> N >> M >> P;
  rep(i, M) {
    int a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    edge[a].eb(mp(b, c - P));
    redge[b].eb(mp(a, c - P));
  }

  memset(visited, false, sizeof(visited));
  visited[N - 1] = true;
  queue<int> q;
  q.push(N - 1);
  while (!q.empty()) {
    int cur = q.front();
    q.pop();

    rep(i, redge[cur].size()) {
      int next = redge[cur][i].F;
      if (visited[next]) continue;
      visited[next] = true;
      q.push(next);
    }
  }

  rep(i, N) d[i] = -INF;
  d[0] = 0;
  bool updated = true;
  rep(_, 2 * N) {
    updated = false;
    rep(i, N) if (d[i] != -INF) rep(j, edge[i].size()) {
      int next = edge[i][j].F;
      int cost = edge[i][j].S;
      if (d[next] < d[i] + cost) {
        d[next] = d[i] + cost;
        updated |= visited[next];
      }
    }
  }

  if (updated)
    cout << "-1" << endl;
  else
    cout << max(d[N - 1], 0LL) << endl;
}
