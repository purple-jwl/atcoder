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
  vector<int> cnt(26, 0);
  int h, w;
  cin >> h >> w;
  rep(i, h) rep(j, w) {
    char c;
    cin >> c;
    cnt[c - 'a']++;
  }

  rep(i, h / 2) rep(j, w / 2) rep(k, 26) if (cnt[k] >= 4) {
    cnt[k] -= 4;
    break;
  }

  if (h % 2) rep(i, w / 2) rep(j, 26) if (cnt[j] >= 2) {
      cnt[j] -= 2;
      break;
    }
  if (w % 2) rep(i, h / 2) rep(j, 26) if (cnt[j] >= 2) {
      cnt[j] -= 2;
      break;
    }

  if (h % 2 && w % 2) rep(j, 26) if (cnt[j] >= 1) {
      cnt[j]--;
      break;
    }

  bool f = true;
  rep(i, 26) if (cnt[i] > 0) f = false;

  cout << (f ? "Yes" : "No") << endl;
}
