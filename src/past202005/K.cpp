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
const int INF = 1 << 30;
// const ll INF = 1LL << 60;
// const ll MOD = 1000000007;

int table[200000];
int parent[200000];
int child[200000];
int root[200000];

void solve(int idx, int x) {
  root[x] = idx;
  if (parent[x] != INF) solve(idx, parent[x]);
}

int main() {
  int N, Q;
  cin >> N >> Q;

  rep(i, N) {
    table[i] = i;
    parent[i] = INF;
    child[i] = -1;
    root[i] = -1;
  }

  rep(_, Q) {
    int f, t, x;
    cin >> f >> t >> x;
    f--;
    t--;
    x--;

    // table f
    int tmp = table[f];
    table[f] = parent[x];
    if (parent[x] != INF) child[parent[x]] = -1;

    // table t
    if (table[t] == INF) {
      parent[x] = INF;
      table[t] = tmp;
    } else {
      child[table[t]] = x;
      parent[x] = table[t];
      table[t] = tmp;
    }
  }

  rep(i, N) if (table[i] != INF) solve(i + 1, table[i]);

  rep(i, N) cout << root[i] << endl;
}
