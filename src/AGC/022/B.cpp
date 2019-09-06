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

int main() {
  int N;
  cin >> N;

  if (N == 3) {
    cout << "2 5 63" << endl;
    return 0;
  }

  vector<int> vi;
  REP(i, 2, 30001) if (i % 2 == 0 || i % 3 == 0) vi.eb(i);

  random_device rd;
  mt19937 engine(rd());

  while (1) {
    shuffle(all(vi), engine);

    int sum = 0;
    int g = vi[0];
    rep(i, N) {
      sum += vi[i];
      g = __gcd(g, vi[i]);
    }

    if (g != 1) continue;

    bool flg = true;
    rep(i, N) if (__gcd(sum, vi[i]) == 1) flg = false;

    if (!flg) continue;

    rep(i, N) cout << vi[i] << ' ';
    cout << endl;
    return 0;
  }
}
