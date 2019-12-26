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
  string a;
  cin >> a;
  if (a.size() == 1)
    cout << 0 << endl;
  else {
    string ra = a;
    reverse(all(ra));

    int cnt = 0;
    rep(i, a.size()) if (a[i] == ra[i]) cnt++;

    int ans = 0;
    if (cnt == a.size() - 2) {
      ans = 25 * cnt + 48;
    } else {
      if (cnt == a.size() && a.size() % 2)
        ans = 25 * (a.size() - 1);
      else
        ans = 25 * a.size();
    }

    cout << ans << endl;
  }
}
