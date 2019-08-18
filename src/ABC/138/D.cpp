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

vector<int> edge[200000];
ll cnt[200000];
ll ans[200000];

void dfs(int pos, int bef, ll sum) {
  sum += cnt[pos];
  ans[pos] = sum;

  rep(i, edge[pos].size()) {
    int next = edge[pos][i];
    if (next == bef) continue;
    dfs(next, pos, sum);
  }
}

int main() {
  int N, Q;
  cin >> N >> Q;
  rep(i, N - 1) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    edge[a].eb(b);
    edge[b].eb(a);
  }
  rep(i, Q) {
    int p, x;
    cin >> p >> x;
    p--;
    cnt[p] += x;
  }
  dfs(0, -1, 0);

  rep(i, N) {
    if (i) cout << " ";
    cout << ans[i];
  }
  cout << endl;
}
