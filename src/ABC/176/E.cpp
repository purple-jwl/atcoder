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
  int H, W, M;
  cin >> H >> W >> M;
  vector<int> h(M), w(M), hcnt(H, 0), wcnt(W, 0);
  rep(i, M) {
    cin >> h[i] >> w[i];
    h[i]--;
    w[i]--;
    hcnt[h[i]]++;
    wcnt[w[i]]++;
  }

  vector<int> _hcnt = hcnt, _wcnt = wcnt;
  sort(rall(_hcnt));
  sort(rall(_wcnt));

  ll ht = 0;
  ll wt = 0;
  rep(i, H) if (hcnt[i] == _hcnt[0]) ht++;
  rep(i, W) if (wcnt[i] == _wcnt[0]) wt++;

  int cnt = 0;
  rep(i, M) if (hcnt[h[i]] == _hcnt[0] && wcnt[w[i]] == _wcnt[0]) cnt++;

  int ans = _hcnt[0] + _wcnt[0];
  if (cnt == ht * wt) ans--;

  cout << ans << endl;
}
