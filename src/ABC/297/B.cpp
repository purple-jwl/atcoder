#include <bits/stdc++.h>

#define REP(i, x, n) for (int i = x; i < (int)(n); i++)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define uniq(x) x.erase(unique(x.begin(), x.end()), x.end())

using namespace std;

typedef long long ll;

int main() {
  vector<int> b, r;
  int k;

  rep(i, 8) {
    char c;
    cin >> c;
    if (c == 'B') b.push_back(i);
    if (c == 'K') k = i;
    if (c == 'R') r.push_back(i);
  }

  bool f = true;
  if ((b[0] + b[1]) % 2 == 0) f = false;
  if (k < r[0] || r[1] < k) f = false;

  cout << (f ? "Yes" : "No") << endl;
}
