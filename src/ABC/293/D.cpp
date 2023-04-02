#include <bits/stdc++.h>

#define REP(i, x, n) for (int i = x; i < (int)(n); i++)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define uniq(x) x.erase(unique(x.begin(), x.end()), x.end())

using namespace std;

typedef long long ll;

struct UnionFindTree {
  vector<int> data;

  UnionFindTree(int sz) { data.assign(sz, -1); }

  bool unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return false;
    if (data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return true;
  }

  int find(int k) {
    if (data[k] < 0) return k;
    return data[k] = find(data[k]);
  }

  bool same(int x, int y) { return find(x) == find(y); }

  int size(int k) { return -data[find(k)]; }
};

int main() {
  int n, m;
  cin >> n >> m;
  int x = 0, y = n;
  UnionFindTree uf(n);
  rep(i, m) {
    int a, c;
    char b, d;
    cin >> a >> b >> c >> d;
    if (uf.same(a, c)) {
      x++;
      y--;
    } else {
      uf.unite(a, c);
      y--;
    }
  }
  cout << x << ' ' << y << endl;
}
