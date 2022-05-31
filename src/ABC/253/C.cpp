#include <bits/stdc++.h>

#define REP(i, x, n) for (int i = x; i < (int)(n); i++)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define uniq(x) x.erase(unique(x.begin(), x.end()), x.end())
#define F first
#define S second
#define mp make_pair
#define eb emplace_back
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

typedef long long ll;

/* --- INFやMODの値が適切か確認する --- */
// const int INF = 1 << 30;
// const ll INF = 1LL << 60;
// const ll MOD = 1000000007;

int main() {
  map<int, int> ss;

  int q;
  cin >> q;
  while (q--) {
    int op;
    cin >> op;

    if (op == 1) {
      int x;
      cin >> x;
      ss[x]++;
    }
    if (op == 2) {
      int x, c;
      cin >> x >> c;
      if (ss[x] > c)
        ss[x] -= c;
      else
        ss.erase(x);
    }
    if (op == 3) {
      cout << (ss.rbegin()->F - ss.begin()->F) << endl;
    }
  }
}
