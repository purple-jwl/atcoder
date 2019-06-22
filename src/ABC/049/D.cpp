#include <bits/stdc++.h>

#define REP(i, x, n) for (int i = x; i < (int)(n); i++)
#define rep(i, n) REP (i, 0, n)
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

using namespace std;

typedef long long ll;

// const int INF = 1 << 30;
// const ll INF = 1LL << 60;
// const int MOD = 1000000007;

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
  int N, K, L;
  cin >> N >> K >> L;

  UnionFindTree a(N), b(N);

  rep (i, K) {
    int p, q;
    cin >> p >> q;
    a.unite(p - 1, q - 1);
  }

  rep (i, L) {
    int r, s;
    cin >> r >> s;
    b.unite(r - 1, s - 1);
  }

  vector<pair<int, int>> vp(N);
  map<pair<int, int>, int> cnt;

  rep (i, N) {
    vp[i] = mp(a.find(i), b.find(i));
    cnt[vp[i]]++;
  }

  rep (i, N) cout << (i == 0 ? "" : " ") << cnt[vp[i]];
  cout << endl;
}
