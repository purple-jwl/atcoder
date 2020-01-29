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

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int h, w;
int a[1000][1000], cnt[1000][1000];

ll rec(int y, int x) {
  if (cnt[y][x] != -1) return cnt[y][x];

  ll sum = 1;
  rep(i, 4) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if (!(0 <= ny && ny < h && 0 <= nx && nx < w)) continue;
    if (a[y][x] >= a[ny][nx]) continue;

    sum = (sum + rec(ny, nx)) % MOD;
  }

  return cnt[y][x] = sum;
}

int main() {
  cin >> h >> w;
  rep(i, h) rep(j, w) {
    cin >> a[i][j];
    cnt[i][j] = -1;
  }

  rep(i, h) rep(j, w) if (cnt[i][j] == -1) rec(i, j);

  ll ans = 0;
  rep(i, h) rep(j, w) ans = (ans + cnt[i][j]) % MOD;

  cout << ans << endl;
}
