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
// const ll INF = 1LL << 60;
// const int MOD = 1000000007;

int main() {
  int N, T;
  cin >> N >> T;

  vector<int> A(N);
  rep (i, N) cin >> A[i];

  int maxv = 0;
  int tmp = INF;
  rep (i, N) {
    tmp = min(tmp, A[i]);
    maxv = max(maxv, A[i] - tmp);
  }

  int ans = 0;
  map<int, int> cnt;
  rep (i, N) {
    if (cnt.find(A[i] - maxv) != cnt.end()) {
      ans += cnt[A[i] - maxv];
    }
    cnt[A[i]]++;
  }

  cout << ans <<endl;
}
