#include <bits/stdc++.h>

#define REP(i, x, n) for (int i = x; i < (int)(n); i++)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define uniq(x) x.erase(unique(x.begin(), x.end()), x.end())

using namespace std;

typedef long long ll;

ll f(int t) { return t * t + 2 * t + 3; }

int main() {
  int t;
  cin >> t;
  cout << f(f(f(t) + t) + f(f(t))) << endl;
}
