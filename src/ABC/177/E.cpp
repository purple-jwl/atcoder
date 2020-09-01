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

const int MAX = 1000000 + 1;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  vector<int> cnt(MAX, 0);
  rep(i, n) {
    int b = a[i];
    for (int j = 2; j * j <= b; j++) {
      if (b % j == 0) cnt[j]++;
      while (b % j == 0) b /= j;
    }
    if (b != 1) cnt[b]++;
  }

  bool f = true;
  rep(i, MAX) if (cnt[i] > 1) f = false;

  if (f) {
    cout << "pairwise coprime" << endl;
    return 0;
  }

  int _g = a[0];
  rep(i, n) _g = __gcd(_g, a[i]);

  cout << (_g == 1 ? "setwise coprime" : "not coprime") << endl;
}
