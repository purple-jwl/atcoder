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
  string s;
  cin >> s;

  vector<ll> cnt(1 << 10, 0);
  cnt[0] = 1;
  ll ans = 0;
  int cur = 0;
  rep(i, s.size()) {
    int d = s[i] - '0';
    cur ^= (1 << d);
    ans += cnt[cur];
    cnt[cur]++;
    // cout << "-- " << ans << " " << bitset<10>(cur) << endl;
  }

  cout << ans << endl;
}
