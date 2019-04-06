#include <bits/stdc++.h>

#define REP(i, x, n) for (int i = x; i < (int)(n); i++)
#define rep(i, n) REP (i, 0, n)
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

using namespace std;

typedef long long ll;

const int INF = 1 << 30;

int main() {
  int X, Y, Z, K;
  cin >> X >> Y >> Z >> K;

  vector<ll> A(X), B(Y), C(Z);
  rep (i, X) cin >> A[i];
  rep (i, Y) cin >> B[i];
  rep (i, Z) cin >> C[i];

  vector<ll> AB;
  rep (i, X) rep (j, Y) AB.eb(A[i] + B[j]);

  sort(rall(AB));

  vector<ll> ans;
  rep (i, min(K, sz(AB))) rep (j, Z) {
    ans.eb(AB[i] + C[j]);
  }

  sort(rall(ans));

  rep (i, K) cout << ans[i] << endl;
}
