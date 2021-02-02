#include <bits/stdc++.h>

#define REP(i, x, n) for (int i = x; i < (int)(n); i++)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define popcount(x) __builtin_popcount(x)
#define popcountll(x) __builtin_popcountll(x)
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
  int n, a;
  cin >> n >> a;
  a--;
  string k;
  cin >> k;
  vector<int> b(n);
  rep(i, n) cin >> b[i], b[i]--;

  int m = 0;
  if (k.size() >= 6) {
    m = 200000;
  } else {
    m = stoi(k);
    k = "";
  }

  vector<int> step(n, -1);
  vector<int> rb(n);
  int cycleCnt = 0;

  bool f = true;
  rep(i, m) {
    step[a] = i;

    if (step[b[a]] != -1 && f) {
      f = false;
      cycleCnt = i - step[b[a]] + 1;

      int _a = b[a];
      while (1) {
        rb[b[_a]] = _a;
        _a = b[_a];
        if (_a == b[a]) break;
      }
    }

    a = b[a];
  }

  int rem = 0;
  rep(i, k.size()) { rem = (10 * rem + (k[i] - '0')) % cycleCnt; }

  rep(i, rem) a = b[a];

  if (k.size() > 0) rep(i, 200000) a = rb[a];

  cout << a + 1 << endl;
}
