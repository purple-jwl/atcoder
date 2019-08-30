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

vector<int> edge[100000];
int prevv[100000];
bool visited[100000];

int main() {
  int n, m;
  cin >> n >> m;
  rep(i, n) prevv[i] = -1;
  int s, g;
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    edge[a].eb(b);
    edge[b].eb(a);
    if (i == 0) {
      s = a;
      g = b;
      visited[s] = visited[g] = true;
      prevv[g] = s;
    }
  }

  int cnt = 2;
  while (true) {
    int ns = -1;
    rep(i, edge[s].size()) {
      if (!visited[edge[s][i]]) ns = edge[s][i];
      if (ns != -1) break;
    }

    if (ns != -1) {
      cnt++;
      prevv[s] = ns;
      s = ns;
      visited[s] = true;
      continue;
    }

    int ng = -1;
    rep(i, edge[g].size()) {
      if (!visited[edge[g][i]]) ng = edge[g][i];
      if (ng != -1) break;
    }

    if (ng != -1) {
      cnt++;
      prevv[ng] = g;
      g = ng;
      visited[g] = true;
      continue;
    }

    break;
  }

  cout << cnt << endl;
  for (int i = g; i != -1; i = prevv[i]) cout << i + 1 << ' ';
  cout << endl;
}
