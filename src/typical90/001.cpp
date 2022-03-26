#include <bits/stdc++.h>

#define REP(i, x, n) for (int i = x; i < (int)(n); i++)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
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
  int N, L, K;
  cin >> N >> L >> K;
  vector<int> A(N);
  rep(i, N) cin >> A[i];

  vector<int> B(N + 1);
  B[0] = A[0];
  rep(i, N - 1) B[i + 1] = A[i + 1] - A[i];
  B[N] = L - A[N - 1];

  int ok = 0;
  int ng = L + 1;

  while (abs(ok - ng) > 1) {
    int mid = (ok + ng) / 2;

    int cnt = 0;
    int sum = 0;

    rep(i, B.size()) {
      sum += B[i];
      if (sum >= mid) {
        sum = 0;
        cnt++;
      }
    }

    if (cnt >= K + 1)
      ok = mid;
    else
      ng = mid;
  }

  cout << ok << endl;
}
