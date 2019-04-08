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

ll N, X;
ll pCnt[50 + 1], pbCnt[50 + 1];

ll rec(ll l, ll r, int n) {
  if (X < l) return 0;
  if (1 <= l && r <= X) return pCnt[n];

  ll mid = (r - l) / 2 + l;
  ll res = 0;
  if (X < mid) res += rec(l + 1, mid - 1, n - 1);
  else res += rec(l + 1, mid - 1, n - 1) + rec(mid + 1, r - 1, n - 1) + 1;

  return res;
}

int main() {
  pCnt[0] = pbCnt[0] = 1;
  rep (i, 50) {
    pCnt[i + 1] = 2 * pCnt[i] + 1;
    pbCnt[i + 1] = 2 * pbCnt[i] + 3;
  }

  cin >> N >> X;
  cout << rec(1, pbCnt[N], N) << endl;
}
