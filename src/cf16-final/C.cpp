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
  int n, m;
  cin >> n >> m;
  vector<vector<int>> L(m, vector<int>());
  rep(i, n) {
    int k;
    cin >> k;
    rep(j, k) {
      int l;
      cin >> l;
      L[l - 1].eb(i);
    }
  }

  UnionFindTree uf(n);
  rep(i, m) {
    rep(j, L[i].size()) { uf.unite(L[i][0], L[i][j]); }
  }

  cout << (uf.getSize(0) == n ? "YES" : "NO") << endl;
}
