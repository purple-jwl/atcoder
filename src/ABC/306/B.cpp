#include <bits/stdc++.h>

#define REP(i, x, n) for (int i = x; i < (int)(n); i++)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define uniq(x) x.erase(unique(x.begin(), x.end()), x.end())

using namespace std;

typedef unsigned long long ll;

int main() {
  ll ans = 0;
  rep(i, 64) {
    int a;
    cin >> a;
    if (a == 1) ans += (ll)pow(2, i);
  }
  cout << ans << endl;
}
