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
const ll MOD = 998244353;

vector<int> redge[50], cedge[50];
bool rvisited[50], cvisited[50];

int rdfs(int pos) {
  int res = 1;
  rvisited[pos] = 1;

  rep(i, redge[pos].size()) if (!rvisited[redge[pos][i]]) res +=
      rdfs(redge[pos][i]);

  return res;
}

int cdfs(int pos) {
  int res = 1;
  cvisited[pos] = 1;

  rep(i, cedge[pos].size()) if (!cvisited[cedge[pos][i]]) res +=
      cdfs(cedge[pos][i]);

  return res;
}

int main() {
  int N, K;
  cin >> N >> K;
  int a[N][N];
  rep(i, N) rep(j, N) cin >> a[i][j];

  rep(i, N) REP(j, i + 1, N) {
    int f1 = 1, f2 = 1;
    rep(k, N) {
      if (a[i][k] + a[j][k] > K) f1 = 0;
      if (a[k][i] + a[k][j] > K) f2 = 0;
    }
    if (f1) redge[i].eb(j), redge[j].eb(i);
    if (f2) cedge[i].eb(j), cedge[j].eb(i);
  }

  ll ans = 1;
  rep(i, N) {
    vector<int> p;
    if (!rvisited[i]) p.eb(rdfs(i));
    if (!cvisited[i]) p.eb(cdfs(i));

    rep(j, p.size()) rep(k, p[j]) ans = (ans * (k + 1)) % MOD;
  }

  cout << ans << endl;
}
