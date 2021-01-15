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

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> edge[n];
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    edge[a - 1].eb(b - 1);
    edge[b - 1].eb(a - 1);
  }

  vector<int> cost(n, INF), pos(n, -1);

  queue<int> Q;
  Q.push(0);
  cost[0] = 0;

  while (!Q.empty()) {
    int p = Q.front();
    Q.pop();

    rep(i, edge[p].size()) {
      int e = edge[p][i];
      if (cost[e] > cost[p] + 1) {
        cost[e] = cost[p] + 1;
        pos[e] = p;
        Q.push(e);
      }
    }
  }

  bool yes = true;
  rep(i, n) yes &= cost[i] != INF;

  if (!yes)
    cout << "No" << endl;
  else {
    cout << "Yes" << endl;
    REP(i, 1, n) cout << pos[i] + 1 << endl;
  }
}
