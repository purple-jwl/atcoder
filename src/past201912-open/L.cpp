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

class UnionFindTree {
 private:
  int nodeSize;
  vector<int> parent;
  vector<int> rank;
  vector<int> treeSize;

 public:
  UnionFindTree(int ns) {
    nodeSize = ns;
    parent = vector<int>(nodeSize);
    rank = vector<int>(nodeSize, 0);
    treeSize = vector<int>(nodeSize, 1);

    for (int i = 0; i < nodeSize; i++) {
      parent[i] = i;
    }
  }

  int find(int x) {
    if (parent[x] == x) {
      return x;
    } else {
      return parent[x] = find(parent[x]);
    }
  }

  bool unite(int x, int y) {
    x = find(x);
    y = find(y);

    if (x == y) {
      return false;
    }

    if (rank[x] < rank[y]) {
      parent[x] = y;
      treeSize[y] += treeSize[x];
    } else {
      parent[y] = x;
      treeSize[x] += treeSize[y];
      if (rank[x] == rank[y]) {
        rank[x]++;
      }
    }

    return true;
  }

  bool same(int x, int y) { return find(x) == find(y); }

  int getSize(int x) { return treeSize[find(x)]; }
};

int main() {
  double ans = 1LL << 60;

  int n, m;
  cin >> n >> m;
  vector<int> x(n), y(n), c(n);
  rep(i, n) cin >> x[i] >> y[i] >> c[i];
  vector<int> X(m), Y(m), C(m);
  rep(i, m) cin >> X[i] >> Y[i] >> C[i];

  vector<pair<pii, int>> tower;
  rep(i, n) tower.eb(mp(mp(x[i], y[i]), c[i]));

  rep(i, (1 << m)) {
    vector<pair<pii, int>> _tower = tower;
    rep(j, m) if ((i >> j) & 1) _tower.eb(mp(mp(X[j], Y[j]), C[j]));

    vector<pair<double, pii>> edge;
    rep(j, _tower.size()) REP(k, j + 1, _tower.size()) {
      int x1 = _tower[j].F.F;
      int y1 = _tower[j].F.S;
      int c1 = _tower[j].S;
      int x2 = _tower[k].F.F;
      int y2 = _tower[k].F.S;
      int c2 = _tower[k].S;
      double d = (double)((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
      if (c1 != c2) d *= 100;
      edge.eb(mp(d, mp(j, k)));
    }

    sort(all(edge));

    UnionFindTree uf(_tower.size());
    double sum = 0;
    rep(i, edge.size()) {
      double d = sqrt(edge[i].F);
      int u = edge[i].S.F;
      int v = edge[i].S.S;
      if (!uf.same(u, v)) {
        uf.unite(u, v);
        sum += d;
      }
    }

    ans = min(ans, sum);
  }

  printf("%.10f\n", ans);
}
