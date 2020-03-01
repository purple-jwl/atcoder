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

struct BinaryIndexedTree {
  vector<int> data;

  BinaryIndexedTree(int sz) { data.assign(++sz, 0); }

  int sum(int k) {
    int ret = 0;
    for (++k; k > 0; k -= k & -k) ret += data[k];
    return (ret);
  }

  void add(int k, int x) {
    for (++k; k < data.size(); k += k & -k) data[k] += x;
  }
};

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int q;
  cin >> q;

  vector<BinaryIndexedTree> vb(26, BinaryIndexedTree(n));
  rep(i, n) {
    int d = s[i] - 'a';
    vb[d].add(i, 1);
  }

  rep(_, q) {
    int op;
    cin >> op;
    if (op == 1) {
      int i;
      char c;
      cin >> i >> c;
      i--;
      char bc = s[i];
      s[i] = c;
      vb[c - 'a'].add(i, 1);
      vb[bc - 'a'].add(i, -1);
    } else {
      int l, r;
      cin >> l >> r;
      l--;
      r--;
      int ans = 0;
      rep(i, 26) {
        int sum = vb[i].sum(r);
        if (l - 1 >= 0) sum -= vb[i].sum(l - 1);
        if (sum > 0) ans++;
      }
      cout << ans << endl;
    }
  }
}
