#include <bits/stdc++.h>

#define REP(i, x, n) for (int i = x; i < (int)(n); i++)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
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
  int n;
  cin >> n;
  vector<string> s(n);
  rep(i, n) cin >> s[i];

  int ans = 10 * n;
  rep(k, 10) {
    vector<int> cnt(10, 0);
    rep(i, n) rep(j, 10) if (k == (s[i][j] - '0')) cnt[j]++;
    int tmp = 0;
    rep(i, 10) tmp = max(tmp, i + 10 * (cnt[i] - 1));
    ans = min(ans, tmp);
  }

  cout << ans << endl;
}
