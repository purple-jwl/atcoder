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

ll MAX = 200000;
ll cnt[200000 + 1];

int main() {
  ll N, M;
  cin >> N >> M;
  vector<ll> A(N);
  rep(i, N) cin >> A[i];

  sort(all(A));

  rep(i, N) cnt[A[i]]++;
  for (int i = MAX; i > 0; i--) cnt[i - 1] += cnt[i];

  int ok = 2;
  int ng = MAX * 2 + 1;

  while (abs(ok - ng) > 1) {
    int mid = (ok + ng) / 2;

    ll _cnt = 0;
    rep(i, N) {
      int idx = max(0LL, mid - A[i]);
      _cnt += cnt[idx];
    }

    if (M <= _cnt)
      ok = mid;
    else
      ng = mid;
  }

  vector<ll> sum(N + 1);
  rep(i, N) sum[i + 1] = sum[i] + A[i];

  ll ans = 0;
  ll rem = M;
  rep(i, N) {
    int idx = lower_bound(all(A), ok + 1 - A[i]) - A.begin();
    ans += (sum[N] - sum[idx]);
    ans += (N - idx) * A[i];
    rem -= (N - idx);
  }

  ans += rem * ok;

  cout << ans << endl;
}
