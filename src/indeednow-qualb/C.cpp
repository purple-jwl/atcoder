#include <bits/stdc++.h>

#define REP(i, x, n) for (int i = x; i < (int)(n); i++)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
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

int main() {
  int n;
  cin >> n;
  vector<int> edge[n + 1];
  rep(i, n - 1) {
    int a, b;
    cin >> a >> b;
    edge[a].eb(b);
    edge[b].eb(a);
  }

  vector<int> ans;
  vector<bool> used(n + 1, 0);
  priority_queue<int, vector<int>, greater<int>> pq;
  pq.push(1);
  used[1] = 1;

  while (!pq.empty()) {
    int p = pq.top();
    pq.pop();

    ans.eb(p);

    rep(i, edge[p].size()) {
      int v = edge[p][i];
      if (used[v]) continue;
      used[v] = 1;
      pq.push(v);
    }
  }

  rep(i, ans.size()) {
    if (i) cout << ' ';
    cout << ans[i];
  }
  cout << endl;
}
