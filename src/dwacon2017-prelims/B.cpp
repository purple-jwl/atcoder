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

int f(string t) {
  int res = 0;
  rep(i, t.size()) {
    int j = i;
    while (j + 1 < t.size() && t[j] == '2' && t[j + 1] == '5') j += 2;
    res = max(res, j - i);
    i = j;
  }
  return res;
}

int main() {
  string t;
  cin >> t;

  string t1 = "";
  string t2 = "";
  rep(i, t.size()) {
    t1 += (t[i] != '?' ? t[i] : i % 2 ? '2' : '5');
    t2 += (t[i] != '?' ? t[i] : i % 2 ? '5' : '2');
  }

  cout << max(f(t1), f(t2)) << endl;
}

// int dp[100005];

// int main() {
//   string t;
//   cin >> t;

//   int ans = 0;
//   rep(i, t.size() - 1) {
//     if ((t[i] == '2' || t[i] == '?') && (t[i + 1] == '5' || t[i + 1] == '?'))
//     {
//       dp[i + 2] = max(dp[i + 2], dp[i] + 2);
//     }
//     ans = max(ans, dp[i + 2]);
//   }

//   cout << ans << endl;
// }
