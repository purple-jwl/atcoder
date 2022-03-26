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
  int h, w;
  cin >> h >> w;

  UnionFindTree uf(h * w);
  bool painted[h][w];
  memset(painted, false, sizeof(painted));

  int q;
  cin >> q;
  while (q--) {
    int op;
    cin >> op;
    if (op == 1) {
      int r, c;
      cin >> r >> c;
      r--;
      c--;
      painted[r][c] = true;

      int dc[] = {1, -1, 0, 0};
      int dr[] = {0, 0, 1, -1};
      rep(i, 4) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (!(0 <= nr && nr < h && 0 <= nc && nc < w)) continue;
        if (!painted[nr][nc]) continue;
        uf.unite(r * w + c, nr * w + nc);
      }
    } else {
      int ra, ca, rb, cb;
      cin >> ra >> ca >> rb >> cb;
      ra--;
      ca--;
      rb--;
      cb--;
      bool f = painted[ra][ca] && painted[rb][cb] &&
               uf.same(ra * w + ca, rb * w + cb);
      cout << (f ? "Yes" : "No") << endl;
    }
  }
}
