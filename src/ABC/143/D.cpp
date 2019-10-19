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
  vector<int> l(n);
  vector<int> cnt(3000, 0);
  rep(i, n) {
    cin >> l[i];
    cnt[l[i]]++;
  }

  vector<ll> sum(3000, 0);
  REP(i, 1, 3000) sum[i] = sum[i - 1] + cnt[i];

  ll ans = 0;
  rep(i, n) REP(j, i + 1, n) {
    int x = abs(l[i] - l[j]);
    int y = l[i] + l[j];
    ans += sum[y - 1] - sum[x];
    if (x < l[i] && l[i] < y) ans--;
    if (x < l[j] && l[j] < y) ans--;
  }

  cout << ans / 3 << endl;
}
