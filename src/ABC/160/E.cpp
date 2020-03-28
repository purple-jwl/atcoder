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
  ll X, Y, A, B, C;
  cin >> X >> Y >> A >> B >> C;

  vector<ll> p(A), q(B), r(C);
  rep(i, A) cin >> p[i];
  rep(i, B) cin >> q[i];
  rep(i, C) cin >> r[i];

  sort(rall(p));
  sort(rall(q));
  sort(rall(r));

  priority_queue<ll, vector<ll>, greater<ll>> pq;
  rep(i, X) pq.push(p[i]);
  rep(i, Y) pq.push(q[i]);

  rep(i, C) {
    ll v = pq.top();

    if (v > r[i]) break;

    pq.pop();
    pq.push(r[i]);
  }

  ll ans = 0;
  while (!pq.empty()) {
    ans += pq.top();
    pq.pop();
  }

  cout << ans << endl;
}
