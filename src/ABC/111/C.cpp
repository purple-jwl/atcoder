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

int a[100001], b[100001];

int main() {
  int n;
  cin >> n;
  rep(i, n) {
    int v;
    cin >> v;
    if (i % 2)
      a[v]++;
    else
      b[v]++;
  }
  vector<pii> aa, bb;
  rep(i, 100001) {
    if (a[i] != 0) aa.eb(mp(a[i], i));
    if (b[i] != 0) bb.eb(mp(b[i], i));
  }
  sort(rall(aa));
  sort(rall(bb));
  aa.eb(mp(0, 0));
  bb.eb(mp(0, 0));
  if (aa[0].S == bb[0].S) {
    cout << min(n / 2 - aa[0].F + n / 2 - bb[1].F,
                n / 2 - aa[1].F + n / 2 - bb[0].F)
         << endl;
  } else {
    cout << n / 2 - aa[0].F + n / 2 - bb[0].F << endl;
  }
}
