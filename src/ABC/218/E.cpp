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

  vector<pair<int, pii>> vp;
  rep(i, m) {
    int a, b, c;
    cin >> a >> b >> c;
    vp.eb(mp(c, mp(a - 1, b - 1)));
  }

  sort(all(vp));

  UnionFindTree uf(n);
  ll ans = 0;
  rep(i, m) {
    if (vp[i].F > 0 && uf.same(vp[i].S.F, vp[i].S.S)) ans += vp[i].F;
    else uf.unite(vp[i].S.F, vp[i].S.S);
  }

  cout << ans << endl;
}
