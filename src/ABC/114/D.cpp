#include <bits/stdc++.h>

#define REP(i, x, n) for (int i = x; i < (int)(n); i++)
#define rep(i, n) REP (i, 0, n)
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

using namespace std;

typedef long long ll;

// const int INF = 1 << 30;
// const ll INF = 1LL << 60;

int main() {
  int cnt[100] = {0};
  int n;
  cin >> n;

  rep (i, n) {
    int tmp = i + 1;
    REP (j, 2, n) {
      while (tmp % j == 0) {
        cnt[j]++;
        tmp /= j;
      }
    }
  }

  int a, b, c;
  a = b = c = 0;
  REP (i, 1, n) {
    if (cnt[i] >= 74) a++;
    REP (j, 1, n) {
      if (i == j) continue;
      if (cnt[i] >= 2 && cnt[j] >= 24) b++;
      if (cnt[i] >= 4 && cnt[j] >= 14) b++;
      REP (k, 1, n) {
        if (i == k || j == k) continue;
        if (cnt[i] >= 2 && cnt[j] >= 4 && cnt[k] >= 4) c++;
      }
    }
  }

  cout << a + b + c / 2 << endl;
}
