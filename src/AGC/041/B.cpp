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
  ll N, M, V, P;
  cin >> N >> M >> V >> P;
  vector<ll> A(N);
  rep(i, N) cin >> A[i];

  sort(rall(A));

  int ok = 0;
  int ng = N;

  while (abs(ok - ng) > 1) {
    int mid = (ok + ng) / 2;

    if (mid < P) {
      ok = mid;
      continue;
    }

    vector<ll> a = A;
    ll cnt = V * M;
    REP(i, mid, N) {
      if (cnt <= 0) break;
      cnt -= M;
      a[i] += M;
    }
    rep(i, P - 1) {
      if (cnt <= 0) break;
      cnt -= M;
      a[i] += M;
    }

    bool flg = true;
    REP(i, P - 1, mid) if (a[i] > a[mid]) flg = false;
    if (!flg) {
      ng = mid;
      continue;
    }

    REP(i, P - 1, mid) {
      if (cnt <= 0) break;
      cnt -= (a[mid] - a[i]);
    }

    if (cnt > 0)
      ng = mid;
    else
      ok = mid;
  }

  cout << ok + 1 << endl;
}
