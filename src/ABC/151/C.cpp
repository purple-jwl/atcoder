#include <bits/stdc++.h>

#define REP(i, x, n) for (int i = x; i < (int)(n); i++)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x.size())
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
  int n, m;
  cin >> n >> m;
  vector<int> flg(n, 0), wcnt(n, 0);
  rep(i, m) {
    int p;
    string s;
    cin >> p >> s;
    p--;
    if (flg[p] == 0 && s == "WA") wcnt[p]++;
    if (s == "AC") flg[p] = 1;
  }

  int a = 0;
  int b = 0;
  rep(i, n) {
    if (flg[i]) {
      a++;
      b += wcnt[i];
    }
  }

  cout << a << ' ' << b << endl;
}
