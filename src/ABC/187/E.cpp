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

ll sum[200000];
vector<int> edge[200000];
int depth[200000];

void dfs1(int curr, int prev) {
  rep(i, edge[curr].size()) {
    int next = edge[curr][i];
    if (next != prev) {
      depth[next] = depth[curr] + 1;
      dfs1(next, curr);
    }
  }
}

void dfs2(int curr, int prev) {
  rep(i, edge[curr].size()) {
    int next = edge[curr][i];
    if (next != prev) {
      sum[next] += sum[curr];
      dfs2(next, curr);
    }
  }
}

int main() {
  int n;
  cin >> n;

  vector<int> a(n), b(n);

  rep(i, n - 1) {
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
    edge[a[i]].eb(b[i]);
    edge[b[i]].eb(a[i]);
  }

  dfs1(0, -1);

  int q;
  cin >> q;
  rep(_, q) {
    int t, e, x;
    cin >> t >> e >> x;
    e--;

    int _a = a[e];
    int _b = b[e];
    if (t == 2) swap(_a, _b);

    if (depth[_a] < depth[_b]) {
      sum[0] += x;
      sum[_b] -= x;
    } else {
      sum[_a] += x;
    }
  }

  dfs2(0, -1);

  rep(i, n) cout << sum[i] << endl;
}
