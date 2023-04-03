#include <bits/stdc++.h>

#define REP(i, x, n) for (int i = x; i < (int)(n); i++)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define uniq(x) x.erase(unique(x.begin(), x.end()), x.end())

using namespace std;

typedef long long ll;

int main() {
  int n;
  cin >> n;
  vector<vector<int>> edge(2 * n);
  map<string, int> ids;
  vector<int> h(2 * n, 0);
  int c = 0;
  rep(i, n) {
    string s, t;
    cin >> s >> t;
    if (ids.find(s) == ids.end()) ids[s] = c++;
    if (ids.find(t) == ids.end()) ids[t] = c++;
    edge[ids[s]].push_back(ids[t]);
    h[ids[t]]++;
  }

  queue<int> Q;
  rep(i, c) if (h[i] == 0) Q.push(i);

  int vis = 0;
  while (!Q.empty()) {
    int u = Q.front();
    Q.pop();
    vis++;

    rep(i, edge[u].size()) Q.push(edge[u][i]);
  }

  cout << (vis == c ? "Yes" : "No") << endl;
}
