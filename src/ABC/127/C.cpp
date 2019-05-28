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
// const int MOD = 1000000007;

int main() {
  int N, M;
  cin >> N >> M;

  vector<int> cnt(N + 1, 0);
  rep (i, M) {
    int l, r;
    cin >> l >> r;
    cnt[l - 1]++;
    cnt[r - 1 + 1]--;
  }

  rep (i, N - 1) cnt[i + 1] += cnt[i];

  int ans = 0;
  rep (i, N) ans += (cnt[i] == M ? 1 : 0);

  cout << ans << endl;
}
