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
  int r1, c1, r2, c2;
  cin >> r1 >> c1 >> r2 >> c2;

  int r = abs(r1 - r2);
  int c = abs(c1 - c2);

  int ans;
  if (r == 0 && c == 0)
    ans = 0;
  else if (r + c <= 3)
    ans = 1;
  else if (abs(r - c) == 0)
    ans = 1;
  else if (r + c <= 6)
    ans = 2;
  else if ((r + c) % 2 == 0)
    ans = 2;
  else if (abs(r - c) <= 3)
    ans = 2;
  else
    ans = 3;

  cout << ans << endl;
}
