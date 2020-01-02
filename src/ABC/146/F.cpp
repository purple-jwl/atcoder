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
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;

  vector<int> memo(n + 1, -1);
  for (int i = n, j = n; i >= 0; i--) {
    if (s[i] == '0') j = i;
    memo[i] = j;
  }

  vector<int> ans;
  vector<bool> visited(n + 1, 0);
  for (int i = n; i > 0;) {
    visited[i] = 1;
    int next = memo[max(0, i - m)];
    if (visited[next]) {
      cout << -1 << endl;
      return 0;
    }
    ans.eb(i - next);
    i = next;
  }

  reverse(all(ans));

  rep(i, ans.size()) cout << ans[i] << ' ';
  cout << endl;
}
