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

/* --- INFの値が適切か確認する --- */
// const int INF = 1 << 30;
// const ll INF = 1LL << 60;
// const int MOD = 1000000007;

int main() {
  int K;
  cin >> K;
  vector<int> A(K);
  rep(i, K) cin >> A[i];

  reverse(all(A));

  ll L = 2;
  ll R = 2;

  rep(i, K) {
    L = ceil((double)(L) / A[i]) * A[i];
    R = floor((double)(R) / A[i]) * A[i] + A[i] - 1;
    if (L > R) {
      cout << "-1" << endl;
      return 0;
    }
  }

  cout << L << ' ' << R << endl;
}
