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

int main() {
  multiset<ll> pms, mms;
  int q;
  cin >> q;

  while (q--) {
    ll c, x;
    cin >> c >> x;

    if (c == 1) {
      pms.insert(x);
      mms.insert(x * -1);
    } else {
      int k;
      cin >> k;

      ll ans = -1;
      if (c == 2) {
        auto it = mms.lower_bound(x * -1);

        while (--k > 0 && it != mms.end()) it++;
        if (it != mms.end()) ans = *it * -1;
      } else {
        auto it = pms.lower_bound(x);

        while (--k > 0 && it != pms.end()) it++;
        if (it != pms.end()) ans = *it;
      }

      cout << ans << endl;
    }
  }
}
