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
const ll MOD = 1000000007;

vector<int> edge[100];
int cost[100];
ll cnt[100];

int main() {
  int n, a, b, m;
  cin >> n >> a >> b >> m;
  a--;
  b--;
  rep(i, m) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    edge[x].eb(y);
    edge[y].eb(x);
  }

  rep(i, n) cost[i] = INF;
  cost[a] = 0;
  cnt[a] = 1;

  queue<int> q;
  q.push(a);

  while (!q.empty()) {
    int cur = q.front();
    q.pop();

    rep(i, edge[cur].size()) {
      int next = edge[cur][i];
      if (cost[next] >= cost[cur] + 1) {
        cnt[next] = (cnt[next] + cnt[cur]) % MOD;
      }
      if (cost[next] > cost[cur] + 1) {
        cost[next] = cost[cur] + 1;
        q.push(next);
      }
    }
  }

  cout << cnt[b] << endl;
}
