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

/* --- INFの値が適切か確認する --- */
// const int INF = 1 << 30;
// const ll INF = 1LL << 60;
// const int MOD = 1000000007;

// w = lca(u, v)
// Q(u, v) = Q(w, u) + Q(w, v) = Q(root, u) + Q(root, v) - 2 * Q(root, w)
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> cnt(n, 0);
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    cnt[a - 1]++;
    cnt[b - 1]++;
  }
  bool f = true;
  rep(i, n) if (cnt[i] % 2) f = false;
  cout << (f ? "YES" : "NO") << endl;
}
