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
  int N, K;
  cin >> N >> K;

  vector<pair<int, int>> dt(N);
  rep (i, N) cin >> dt[i].S >> dt[i].F;

  sort(rall(dt));

  ll ans = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  map<int, int> cnt;
  rep (i, K) {
    ans += dt[i].F;
    cnt[dt[i].S]++;
    pq.push(dt[i]);
  }
  ans += (ll)sz(cnt) * sz(cnt);

  ll total = ans;
  REP (i, K, N) {
    if (cnt.count(dt[i].S) != 0) continue;

    while (!pq.empty()) {
      pair<int, int> p = pq.top();
      pq.pop();

      if (cnt[p.S] > 1) {
        ll s = sz(cnt);
        total = total + dt[i].F - p.F + (s + 1) * (s + 1) - s * s;
        cnt[p.S]--;
        cnt[dt[i].S]++;
        ans = max(ans, total);
        break;
      }
    }
  }

  cout << ans << endl;
}
