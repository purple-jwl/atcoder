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
  int n, k;
  string s;
  cin >> n >> k;
  cin >> s;

  int nextIdx[n][26];
  rep(j, 26) nextIdx[n - 1][j] = n;
  for (int i = n - 1; i >= 0; i--) {
    rep(j, 26) {
      if (i != n - 1) nextIdx[i][j] = nextIdx[i + 1][j];
      nextIdx[i][s[i] - 'a'] = i;
    }
  }

  string ans = "";
  int idx = 0;
  rep(i, k) rep(j, 26) {
    if (nextIdx[idx][j] == n) continue;
    if (ans.size() + (n - nextIdx[idx][j]) < k) continue;
    ans += (char)('a' + j);
    idx = nextIdx[idx][j] + 1;
    break;
  }

  cout << ans << endl;

  // stack<char> st;
  // rep(i, n) {
  //   while (1) {
  //     if (st.size() == 0) break;
  //     char c = st.top();
  //     if (c <= s[i]) break;
  //     if (st.size() + (n - i) == k) break;
  //     st.pop();
  //   }
  //   st.push(s[i]);
  // }

  // string ans = "";
  // while (!st.empty()) {
  //   if (st.size() <= k) ans += st.top();
  //   st.pop();
  // }

  // reverse(all(ans));

  // cout << ans << endl;
}
