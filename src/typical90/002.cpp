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

vector<string> ans;

void rec(string s, int l, int r, int n) {
  if (l == n && r == n)
    ans.eb(s);
  else {
    if (l < n) rec(s + "(", l + 1, r, n);
    if (r < n && l > r) rec(s + ")", l, r + 1, n);
  }
}

int main() {
  int n;
  cin >> n;

  if (n % 2 == 0) {
    rec("", 0, 0, n / 2);
  }

  sort(all(ans));

  rep(i, ans.size()) cout << ans[i] << endl;
}
