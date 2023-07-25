#include <bits/stdc++.h>

#define REP(i, x, n) for (int i = x; i < (int)(n); i++)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define uniq(x) x.erase(unique(x.begin(), x.end()), x.end())

using namespace std;

typedef long long ll;

int main() {
  int n, k;
  cin >> n >> k;

  priority_queue<int> Q;
  rep(i, n) {
    int p;
    cin >> p;
    if (i < k)
      Q.push(-p);
    else {
      if (Q.top() > -p) {
        Q.pop();
        Q.push(-p);
      }
    }
    if (i >= k - 1) cout << -Q.top() << endl;
  }
}
