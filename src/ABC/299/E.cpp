#include <bits/stdc++.h>

#define REP(i, x, n) for (int i = x; i < (int)(n); i++)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define uniq(x) x.erase(unique(x.begin(), x.end()), x.end())

using namespace std;

typedef long long ll;

const int INF = 1 << 28;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> edge[n];
  rep(i, m) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    edge[u].push_back(v);
    edge[v].push_back(u);
  }

  vector<int> color(n, -1);

  int K;
  cin >> K;

  vector<int> v[K];

  rep(_, K) {
    int p, d;
    cin >> p >> d;

    p--;
    vector<int> dist(n, INF);
    dist[p] = 0;
    queue<int> Q;
    Q.push(p);
    if (d == 0)
      v[_].push_back(p);
    else
      color[p] = 0;

    while (!Q.empty()) {
      int pos = Q.front();
      Q.pop();
      rep(i, edge[pos].size()) {
        int next = edge[pos][i];
        if (dist[next] > dist[pos] + 1) {
          dist[next] = dist[pos] + 1;
          if (dist[next] < d) color[next] = 0;
          if (dist[next] == d) v[_].push_back(next);
          if (dist[next] >= d) continue;
          Q.push(next);
        }
      }
    }
  }

  rep(i, K) {
    bool f = false;
    rep(j, v[i].size()) if (color[v[i][j]] != 0) {
      color[v[i][j]] = 1;
      f = true;
    }
    if (!f) {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
  rep(i, n) cout << (color[i] != 0 ? '1' : '0');
  cout << endl;
}
