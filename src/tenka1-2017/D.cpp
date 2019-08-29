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
  ll N, K;
  cin >> N >> K;
  vector<ll> A(N), B(N);
  rep(i, N) cin >> A[i] >> B[i];

  ll ans = 0;
  rep(i, N) if ((K | A[i]) == K) ans += B[i];

  for (int i = 30; i >= 0; i--) {
    if (K & (1 << i)) {
      ll sum = 0;
      int k = K ^ (1 << i);
      rep(j, i) k |= (1 << j);
      rep(j, N) if ((k | A[j]) == k) sum += B[j];
      ans = max(ans, sum);
    }
  }

  cout << ans << endl;
}
