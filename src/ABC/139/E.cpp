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

int N;
int A[1000][1000];
int idx[1000];
int cnt[1000][1000];

int main() {
  cin >> N;
  rep(i, N) rep(j, N - 1) {
    cin >> A[i][j];
    A[i][j]--;
  }
  int ans = 0;
  queue<pii> q;
  rep(i, N) q.push(mp(i, A[i][0]));

  while (true) {
    ans++;
    queue<pii> tmp;
    bool flg = false;

    while (!q.empty()) {
      pii p = q.front();
      q.pop();
      int a = min(p.F, p.S);
      int b = max(p.F, p.S);
      cnt[a][b]++;
      if (cnt[a][b] == 2) {
        idx[a]++;
        idx[b]++;
        if (idx[a] < N - 1) {
          tmp.push(mp(a, A[a][idx[a]]));
        }
        if (idx[b] < N - 1) {
          tmp.push(mp(b, A[b][idx[b]]));
        }
        flg = true;
      }
    }

    if (flg && tmp.empty()) {
      cout << ans << endl;
      return 0;
    }

    if (!flg) {
      cout << "-1" << endl;
      return 0;
    }

    q = tmp;
  }
}
