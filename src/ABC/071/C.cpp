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
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  sort(all(a));

  vector<ll> v;
  rep(i, n) {
    int pos = i;
    while (pos < n) {
      if (pos + 1 < n && a[i] == a[pos + 1])
        pos++;
      else
        break;
    }
    int cnt = pos - i + 1;
    if (cnt >= 2) v.eb(a[i]);
    if (cnt >= 4) v.eb(a[i]);
    i = pos;
  }

  reverse(all(v));

  if (v.size() < 2)
    cout << "0" << endl;
  else
    cout << v[0] * v[1] << endl;
}
