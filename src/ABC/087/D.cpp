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

int main() {
  int N, M;
  cin >> N >> M;

  vector<pair<int, int>> edge[N];
  rep (i, M) {
    int L, R, D;
    cin >> L >> R >> D;
    edge[L - 1].eb(mp(R - 1, D));
    edge[R - 1].eb(mp(L - 1, D * -1));
  }

  int dist[N];
  rep (i, N) dist[i] = INF;

  rep (i, N) {
    if (dist[i] != INF) continue;
    dist[i] = 0;

    queue<int> Q;
    Q.push(i);

    while (!Q.empty()) {
      int cur = Q.front();
      Q.pop();

      rep (i, sz(edge[cur])) {
        int next = edge[cur][i].F;
        int d = edge[cur][i].S;

        if (dist[next] == INF) {
          dist[next] = dist[cur] + d;
          Q.push(next);
        } else if (dist[next] != dist[cur] + d) {
          cout << "No" << endl;
          return 0;
        }
      }
    }
  }

  cout << "Yes" << endl;
}
