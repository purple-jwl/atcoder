#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

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

    for(int i = 0; i < nodeSize; i++) {
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

  bool same(int x, int y) {
    return find(x) == find(y);
  }

  int getSize(int x) {
    return treeSize[find(x)];
  }
};

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> a(m), b(m);
  for (int i = 0; i < m; i++) {
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
  }

  UnionFindTree uf(n);
  vector<ll> ans;
  ll cnt = (ll)(n - 1) * n / 2;

  for (int i = m - 1; i >= 0; i--) {
    ans.push_back(cnt);

    if (!uf.same(a[i], b[i])) {
      cnt -= (ll)uf.getSize(a[i]) * uf.getSize(b[i]);
      uf.unite(a[i], b[i]);
    }
  }

  for (int i = m - 1; i >= 0; i--) {
    cout << ans[i] << endl;
  }
}
