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

int N, A, B, C;
int l[8];
int ans = 1 << 30;

void rec(int a, int b, int c, int idx, int m) {
  if (idx == N) {
    if (a == 0 || b == 0 || c == 0) return;
    ans = min(ans, abs(A - a) + abs(B - b) + abs(C - c) + m);
  } else {
    rec(a + l[idx], b, c, idx + 1, m + (a == 0 ? 0 : 10));
    rec(a, b + l[idx], c, idx + 1, m + (b == 0 ? 0 : 10));
    rec(a, b, c + l[idx], idx + 1, m + (c == 0 ? 0 : 10));
    rec(a, b, c, idx + 1, m);
  }
}

int main() {
  cin >> N >> A >> B >> C;
  rep(i, N) cin >> l[i];
  rec(0, 0, 0, 0, 0);

  cout << ans << endl;
}
