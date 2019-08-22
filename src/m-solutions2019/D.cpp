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

int main() {
  int n;
  cin >> n;
  vector<int> edge[n];
  rep(i, n - 1) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    edge[a].eb(b);
    edge[b].eb(a);
  }
  vector<int> c(n);
  rep(i, n) cin >> c[i];

  sort(rall(c));

  ll M = 0;
  vector<int> d(n, -1);
  d[0] = c[0];
  int idx = 1;
  queue<int> q;
  q.push(0);
  while (!q.empty()) {
    int cur = q.front();
    q.pop();

    rep(i, edge[cur].size()) {
      int next = edge[cur][i];
      if (d[next] != -1) continue;
      d[next] = c[idx];
      M += c[idx++];
      q.push(next);
    }
  }

  cout << M << endl;
  rep(i, n) cout << d[i] << ' ';
  cout << endl;
}
