#include <bits/stdc++.h>

#define REP(i, x, n) for (int i = x; i < (int)(n); i++)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define uniq(x) x.erase(unique(x.begin(), x.end()), x.end())

using namespace std;

typedef long long ll;

int main() {
  int n, h, x;
  cin >> n >> h >> x;
  vector<int> p(n);
  rep(i, n) cin >> p[i];
  rep(i, n) if (h + p[i] >= x) {
    cout << i + 1 << endl;
    break;
  }
}
