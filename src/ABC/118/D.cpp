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

string cmp(string a, string b) {
  if (sz(a) == sz(b)) return a < b ? b : a;
  return sz(a) < sz(b) ? b : a;
}

int main() {
  int ma[] = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};

  int N, M;
  cin >> N >> M;

  int A[M];
  string dp[N + 1] = {""};
  rep (i, M) {
    cin >> A[i];
    if (ma[A[i]] <= N) dp[ma[A[i]]] = cmp(dp[ma[A[i]]], string() + (char)('0' + A[i]));
  }

  rep (i, N) {
    if (dp[i] == "") continue;
    rep (j, M) {
      if (i + ma[A[j]] > N) continue;
      dp[i + ma[A[j]]] = cmp(dp[i + ma[A[j]]], dp[i] + (char)('0' + A[j]));
    }
  }

  cout << dp[N] << endl;
}
