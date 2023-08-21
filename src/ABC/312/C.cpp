#include <bits/stdc++.h>

#define REP(i, x, n) for (int i = x; i < (int)(n); i++)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define uniq(x) x.erase(unique(x.begin(), x.end()), x.end())

using namespace std;

typedef long long ll;

int main() {
  int n, m;
  cin >> n >> m;
  vector<ll> a(n), b(m);
  rep(i, n) cin >> a[i];
  rep(i, m) cin >> b[i];

  sort(all(a));
  sort(all(b));

  ll ok = 1000000001;
  ll ng = 0;

  while (abs(ok - ng) > 1) {
    ll mid = (ok + ng) / 2;

    int x = 0;
    rep(i, n) if (a[i] <= mid) x++;
    int y = 0;
    rep(i, m) if (mid <= b[i]) y++;

    if (x >= y)
      ok = mid;
    else
      ng = mid;
  }

  cout << ok << endl;
}
