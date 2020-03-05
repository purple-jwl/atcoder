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
  int n, m, k;
  cin >> n >> m >> k;

  UnionFindTree uf(n);
  vector<int> fri(n, 0), nofri(n, 0);

  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    uf.unite(a, b);
    fri[a]++;
    fri[b]++;
  }
  rep(i, k) {
    int c, d;
    cin >> c >> d;
    c--;
    d--;
    if (uf.same(c, d)) {
      nofri[c]++;
      nofri[d]++;
    }
  }

  rep(i, n) { cout << uf.size(i) - 1 - fri[i] - nofri[i] << ' '; }

  cout << endl;
}
