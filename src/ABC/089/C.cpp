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
  int n;
  cin >> n;
  vector<ll> cnt(5, 0);
  rep(i, n) {
    string s;
    cin >> s;
    if (s[0] == 'M') cnt[0]++;
    if (s[0] == 'A') cnt[1]++;
    if (s[0] == 'R') cnt[2]++;
    if (s[0] == 'C') cnt[3]++;
    if (s[0] == 'H') cnt[4]++;
  }

  ll ans = 0;
  REP(i, 0, 5) REP(j, i + 1, 5) REP(k, j + 1, 5) {
    ans += cnt[i] * cnt[j] * cnt[k];
  }

  cout << ans << endl;
}
