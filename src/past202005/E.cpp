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

vector<int> edge[200];
int color[200];

int main() {
  int N, M, Q;
  cin >> N >> M >> Q;
  rep(i, M) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    edge[u].eb(v);
    edge[v].eb(u);
  }
  rep(i, N) cin >> color[i];

  rep(_, Q) {
    int op;
    cin >> op;
    if (op == 1) {
      int x;
      cin >> x;
      x--;
      cout << color[x] << endl;
      rep(i, edge[x].size()) color[edge[x][i]] = color[x];
    } else {
      int x, y;
      cin >> x >> y;
      x--;
      cout << color[x] << endl;
      color[x] = y;
    }
  }
}
