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

// const int INF = 1 << 30;
// const ll INF = 1LL << 60;

int main() {
  int N;
  cin >> N;

  vector<ll> X(N), Y(N);
  rep (i, N) cin >> X[i] >> Y[i];

  int parity = abs(X[0] + Y[0]) % 2;
  rep (i, N) {
    if (parity != abs(X[i] + Y[i]) % 2) {
      cout << "-1" << endl;
      return 0;
    }
  }

  vector<ll> d;
  for (int i = 30; i >= 0; i--) d.eb(1LL << i);
  if (parity == 0) d.eb(1);

  cout << sz(d) << endl;
  rep (i, sz(d)) cout << (i == 0 ? "" : " ") << d[i];
  cout << endl;

  rep (i, N) {
    string w = "";
    rep (j, sz(d)) {
      if (abs(X[i]) < abs(Y[i])) {
        if (Y[i] > 0) {
          Y[i] -= d[j];
          w += 'U';
        } else {
          Y[i] += d[j];
          w += 'D';
        }
      } else {
        if (X[i] > 0) {
          X[i] -= d[j];
          w += 'R';
        } else {
          X[i] += d[j];
          w += 'L';
        }
      }
    }
    cout << w << endl;
  }
}
