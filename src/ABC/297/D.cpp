#include <bits/stdc++.h>

#define REP(i, x, n) for (int i = x; i < (int)(n); i++)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define uniq(x) x.erase(unique(x.begin(), x.end()), x.end())

using namespace std;

typedef long long ll;

int main() {
  ll a, b;
  cin >> a >> b;
  if (a < b) swap(a, b);
  ll cnt = 0;

  while (a != b && a > 0 && b > 0) {
    ll tmp = a % b;
    cnt += a / b;
    if (a % b == 0) cnt--;
    a = b;
    b = tmp;
  }
  cout << cnt << endl;
}
