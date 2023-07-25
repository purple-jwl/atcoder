#include <bits/stdc++.h>

#define REP(i, x, n) for (int i = x; i < (int)(n); i++)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define uniq(x) x.erase(unique(x.begin(), x.end()), x.end())

using namespace std;

typedef long long ll;

vector<ll> lst;

void f(ll v, int p) {
  lst.emplace_back(v);
  int a = v % 10;
  if (a + p >= 0 && a + p < 10) f(v * 10 + a + p, p);
}

int main() {
  REP(i, 1, 10) REP(j, -9, 10) f(i, j);

  sort(all(lst));
  uniq(lst);

  ll x;
  cin >> x;
  cout << *lower_bound(all(lst), x) << endl;
}
