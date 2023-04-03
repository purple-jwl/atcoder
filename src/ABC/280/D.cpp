#include <bits/stdc++.h>

#define REP(i, x, n) for (int i = x; i < (int)(n); i++)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define uniq(x) x.erase(unique(x.begin(), x.end()), x.end())

using namespace std;

typedef long long ll;

int main() {
  ll k;
  cin >> k;
  ll ans = 0;
  for (ll i = 2; i * i <= k; i++) {
    int c = 0;
    while (k % i == 0) k /= i, c++;

    ll v = 0;
    while (c > 0) {
      v += i;
      ll x = v;
      while (x % i == 0) x /= i, c--;
    }
    ans = max(ans, v);
  }
  cout << max(ans, k) << endl;
}
