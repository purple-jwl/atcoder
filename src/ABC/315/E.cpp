#include <bits/stdc++.h>

#define REP(i, x, n) for (int i = x; i < (int)(n); i++)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define uniq(x) x.erase(unique(x.begin(), x.end()), x.end())

using namespace std;

typedef long long ll;

vector<int> edge[200000];
bool visited[200000];

void dfs(int p) {
  if (visited[p]) return;
  visited[p] = 1;

  for (auto np : edge[p]) {
    dfs(np);
  }
  if (p != 0) cout << p + 1 << ' ';
}

int main() {
  int n;
  cin >> n;
  rep(i, n) {
    int c;
    cin >> c;
    rep(j, c) {
      int p;
      cin >> p;
      edge[i].emplace_back(p - 1);
    }
  }
  memset(visited, false, sizeof(visited));
  dfs(0);
  cout << endl;
}
