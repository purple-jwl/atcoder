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
const int INF = 1 << 29;
// const ll INF = 1LL << 60;
// const int MOD = 1000000007;

int N, M, S, T;
vector<int> edge[100000];
int minDist[100000][3];

struct State {
  int pos, dist, ken;
  State(int p, int d, int k) : pos(p), dist(d), ken(k) {}
  bool operator<(const State &stt) const { return stt.dist < dist; }
};

int solve() {
  priority_queue<State> pq;
  pq.push(State(S, 0, 0));
  minDist[S][0] = 0;

  while (!pq.empty()) {
    State stt = pq.top();
    pq.pop();

    rep(i, edge[stt.pos].size()) {
      int to = edge[stt.pos][i];
      int nk = (stt.ken + 1) % 3;
      int dist = stt.dist;
      if(nk == 0) dist++;
      if (minDist[to][nk] > dist) {
        minDist[to][nk] = dist;
        if (nk == 0 && to == T) {
          return minDist[to][nk];
        }
        pq.push(State(to, minDist[to][nk], nk));
      }
    }
  }
  return -1;
}

int main() {
  cin >> N >> M;
  rep(i, M) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    edge[u].eb(v);
  }
  cin >> S >> T;
  S--;
  T--;

  rep(i, N) rep(j, 3) minDist[i][j] = INF;

  cout << solve() << endl;
}
