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
const ll MOD = 1000000007;

int main() {
  int n;
  cin >> n;
  vector<int> cnt(n, 0);
  rep(i, n) {
    int a;
    cin >> a;
    cnt[a]++;
  }

  ll ans = 1;
  if (n % 2) {
    for (int i = 0; i < n; i += 2) {
      if (i == 0 && cnt[i] == 1)
        ;
      else if (i != 0 && cnt[i] == 2)
        ans = ans * 2 % MOD;
      else
        ans = 0;
    }
  } else {
    for (int i = 1; i < n; i += 2) {
      if (cnt[i] == 2)
        ans = ans * 2 % MOD;
      else
        ans = 0;
    }
  }

  cout << ans << endl;
}
