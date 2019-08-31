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
int cnt[100000];

int main() {
  int n, m;
  cin >> n >> m;
  rep(i, n - 1 + m) {
    int a, b;
    cin >> a >> b;
    edge[a - 1].eb(b - 1);
    cnt[b - 1]++;
  }

  queue<int> q;
  rep(i, n) if (cnt[i] == 0) q.push(i);

  vector<int> ans(n, 0);
  while (!q.empty()) {
    int u = q.front();
    q.pop();

    rep(i, edge[u].size()) {
      int v = edge[u][i];
      if (--cnt[v] == 0) {
        q.push(v);
        ans[v] = u + 1;
      }
    }
  }

  rep(i, n) cout << ans[i] << endl;
}
