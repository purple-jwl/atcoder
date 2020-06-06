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

int main() {
  ll N;
  cin >> N;

  vector<int> r(N), c(N);
  rep(i, N) r[i] = c[i] = i + 1;

  int Q;
  cin >> Q;

  int t = 0;

  rep(_, Q) {
    int op;
    cin >> op;
    int a, b;
    if (op == 1) {
      cin >> a >> b;
      swap(r[a - 1], r[b - 1]);
    }
    if (op == 2) {
      cin >> a >> b;
      swap(c[a - 1], c[b - 1]);
    }
    if (op == 3) {
      t = 1 - t;
      rep(i, N) swap(r[i], c[i]);
    }
    if (op == 4) {
      cin >> a >> b;
      ll ans = 0;
      ans += (r[a - 1] - 1) * (t == 0 ? N : 1);
      ans += (c[b - 1] - 1) * (t == 1 ? N : 1);
      cout << ans << endl;
    }
  }
}
