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

/* --- INFの値が適切か確認する --- */
// const int INF = 1 << 30;
// const ll INF = 1LL << 60;
// const int MOD = 1000000007;

int main() {
  ll H, W;
  cin >> H >> W;

  ll ans = H * W;

  for (ll i = 1; i < H; i++) {
    ll h = H - i;
    if (h > 1) {
      vector<ll> s(3);
      s[0] = i * W;
      s[1] = h / 2 * W;
      s[2] = (h - h / 2) * W;
      sort(all(s));
      ans = min(ans, s[2] - s[0]);
    }
    if (W > 1) {
      vector<ll> s(3);
      s[0] = i * W;
      s[1] = h * (W / 2);
      s[2] = h * (W - W / 2);
      sort(all(s));
      ans = min(ans, s[2] - s[0]);
    }
  }

  for (ll i = 1; i < W; i++) {
    ll w = W - i;
    if (w > 1) {
      vector<ll> s(3);
      s[0] = i * H;
      s[1] = w / 2 * H;
      s[2] = (w - w / 2) * H;
      sort(all(s));
      ans = min(ans, s[2] - s[0]);
    }
    if (H > 1) {
      vector<ll> s(3);
      s[0] = i * H;
      s[1] = w * (H / 2);
      s[2] = w * (H - H / 2);
      sort(all(s));
      ans = min(ans, s[2] - s[0]);
    }
  }

  cout << ans << endl;
}
