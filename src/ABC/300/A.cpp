#include <bits/stdc++.h>

#define REP(i, x, n) for (int i = x; i < (int)(n); i++)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define uniq(x) x.erase(unique(x.begin(), x.end()), x.end())

using namespace std;

typedef long long ll;

int main() {
  int n, a, b;
  cin >> n >> a >> b;
  map<int, int> m;
  rep(i, n) {
    int c;
    cin >> c;
    m[c] = i + 1;
  }
  cout << m[a + b] << endl;
}
