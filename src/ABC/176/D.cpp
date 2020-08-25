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
const int INF = 1 << 30;
// const ll INF = 1LL << 60;
// const ll MOD = 1000000007;

char G[1000][1000];
int cost[1000][1000];
int h, w, ch, cw, dh, dw;

#define P pair<int, pii>

int f() {
  ch--;
  cw--;
  dh--;
  dw--;
  cost[ch][cw] = 0;

  priority_queue<P, vector<P>, greater<P>> pq;
  pq.push(mp(0, mp(cw, ch)));

  while (!pq.empty()) {
    P p = pq.top();
    pq.pop();

    if (p.S.F == dw && p.S.S == dh) {
      return p.F;
    }

    for (int y = -2; y <= 2; y++) {
      for (int x = -2; x <= 2; x++) {
        if (y == 0 && x == 0) continue;

        int next = p.F + ((abs(y) + abs(x)) > 1);
        int nx = p.S.F + x;
        int ny = p.S.S + y;

        if (!(0 <= ny && ny < h && 0 <= nx && nx < w)) continue;
        if (G[ny][nx] == '#') continue;
        if (cost[ny][nx] > next) {
          cost[ny][nx] = next;
          pq.push(mp(cost[ny][nx], mp(nx, ny)));
        }
      }
    }
  }

  return -1;
}

int main() {
  cin >> h >> w;
  cin >> ch >> cw;
  cin >> dh >> dw;

  rep(i, h) rep(j, w) cin >> G[i][j];

  rep(i, h) rep(j, w) cost[i][j] = INF;

  cout << f() << endl;
}
