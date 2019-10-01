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
  string s;
  cin >> s;

  int v[4];
  rep(i, 4) v[i] = (int)(s[i] - '0');

  char ch[] = {'+', '-'};
  rep(i, 2) rep(j, 2) rep(k, 2) {
    int tmp = v[0];
    tmp += (i == 0 ? v[1] : -v[1]);
    tmp += (j == 0 ? v[2] : -v[2]);
    tmp += (k == 0 ? v[3] : -v[3]);
    if (tmp == 7) {
      cout << v[0] << ch[i] << v[1] << ch[j] << v[2] << ch[k] << v[3] << "=7"
           << endl;
      return 0;
    }
  }
}
