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
const ll MOD = 1000000007;

int N, K;
vector<int> edge[100000];

ll rec(int cur, int prev) {
  ll res = 1;
  ll color = prev == -1 ? K - 1 : K - 2;

  rep(i, edge[cur].size()) {
    if (edge[cur][i] == prev) continue;
    res = res * rec(edge[cur][i], cur) % MOD;
    res = res * (color--) % MOD;
  }

  return res;
}

int main() {
  cin >> N >> K;
  rep(i, N - 1) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    edge[a].eb(b);
    edge[b].eb(a);
  }

  int ans = rec(0, -1) * K % MOD;
  cout << ans << endl;
}
