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

// const int INF = 1 << 29;
// const ll INF = 1LL << 60;
// const int MOD = 1000000007;

int main() {
  int N;
  cin >> N;

  vector<pair<ll, ll>> ba(N);
  rep (i, N) {
    int a, b;
    cin >> a >> b;
    ba[i] = mp(b, a);
  }

  sort(all(ba));

  ll sum = 0;
  rep (i, N) {
    sum += ba[i].S;
    if (ba[i].F < sum) {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
}
