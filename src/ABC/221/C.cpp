#include <bits/stdc++.h>

#define REP(i, x, n) for (int i = x; i < (int)(n); i++)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define uniq(x) x.erase(unique(x.begin(), x.end()), x.end())

using namespace std;

typedef long long ll;

int main() {
  string n;
  cin >> n;
  sort(all(n));

  ll ans = 0;
  do {
    rep(i, n.size()) {
      ll a = 0, b = 0;
      for (int j = 0; j < i; j++) a = 10 * a + (n[j] - '0');
      for (int j = i; j < n.size(); j++) b = 10 * b + (n[j] - '0');
      if (a != 0 && b != 0) ans = max(ans, a * b);
    }

  } while (next_permutation(all(n)));

  cout << ans << endl;
}
