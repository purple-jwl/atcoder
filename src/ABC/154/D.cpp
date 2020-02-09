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
  int N, K;
  cin >> N >> K;
  vector<double> p(N);
  rep(i, N) cin >> p[i];

  vector<double> sum(N + 1, 0);
  rep(i, N) {
    sum[i + 1] = sum[i];
    sum[i + 1] += p[i] * (p[i] + 1) / 2 / p[i];
    //    cout << sum[i + 1] << endl;
  }

  double ans = 0;
  REP(i, K, N + 1) {
    //    cout << sum[i] - sum[i - K] << endl;
    ans = max(ans, sum[i] - sum[i - K]);
  }

  printf("%.10f\n", ans);
}
