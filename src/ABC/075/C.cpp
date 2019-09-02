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
// const ll INF = 1LL << 60;
// const int MOD = 1000000007;

vector<pii> edge[50];
bool visited[50];

int main() {
  int n, m;
  cin >> n >> m;
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    edge[a].eb(mp(b, i));
    edge[b].eb(mp(a, i));
  }

  int ans = 0;
  rep(i, m) {
    memset(visited, false, sizeof(visited));
    int cnt = 1;
    queue<int> q;
    q.push(0);
    visited[0] = true;
    while (!q.empty()) {
      int cur = q.front();
      q.pop();
      rep(j, edge[cur].size()) {
        int next = edge[cur][j].F;
        int idx = edge[cur][j].S;
        if (idx == i || visited[next]) continue;
        visited[next] = true;
        q.push(next);
        cnt++;
      }
    }
    if (cnt != n) ans++;
  }

  cout << ans << endl;
}
