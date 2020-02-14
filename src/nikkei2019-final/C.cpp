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

ll f(vector<ll> cnt) {
  int n = cnt.size();

  ll sum = 0;
  rep(i, n) sum += cnt[i];

  int idx = -1;
  ll c = 0;
  rep(i, n) {
    c += cnt[i];
    if (sum <= 2 * c) {
      idx = i;
      break;
    }
  }

  ll res = 0;
  rep(i, n) res += cnt[i] * abs(i - idx);

  return res;
}

int main() {
  int H, W, K;
  cin >> H >> W >> K;
  vector<ll> hcnt(H, W), wcnt(W, H);
  rep(i, K) {
    int r, c;
    cin >> r >> c;
    hcnt[r - 1]--;
    wcnt[c - 1]--;
  }

  cout << f(hcnt) + f(wcnt) << endl;
}
