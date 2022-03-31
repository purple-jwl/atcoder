#include <bits/stdc++.h>

#define REP(i, x, n) for (int i = x; i < (int)(n); i++)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
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

int n, m;
vector<pii> edge[100000];

vector<int> func(int s) {
  vector<int> dist(n, INF);
  dist[s] = 0;

  priority_queue<pii, vector<pii>, greater<pii>> pq;
  pq.push(mp(0, s));

  while (!pq.empty()) {
    int d = pq.top().F;
    int pos = pq.top().S;
    pq.pop();

    rep(i, edge[pos].size()) {
      int next = edge[pos][i].F;
      int c = edge[pos][i].S;

      if (dist[next] > dist[pos] + c) {
        dist[next] = dist[pos] + c;
        pq.push(mp(dist[next], next));
      }
    }
  }

  return dist;
}

int main() {
  cin >> n >> m;
  rep(i, m) {
    int a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    edge[a].eb(mp(b, c));
    edge[b].eb(mp(a, c));
  }

  vector<int> d1 = func(0);
  vector<int> dn = func(n - 1);
  rep(i, n) cout << d1[i] + dn[i] << endl;
}
