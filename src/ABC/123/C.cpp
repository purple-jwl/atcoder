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

const ll INF = 1LL << 60;

int main() {
  ll N, X = INF;
  cin >> N;
  rep (i, 5) {
    ll x;
    cin >> x;
    X = min(X, x);
  }

  cout << (N / X + (N % X ? 1 : 0) + 4) << endl;
}
