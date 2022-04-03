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
// const int INF = 1 << 30;
// const ll INF = 1LL << 60;
// const ll MOD = 1000000007;

int main() {
  int n, k, x;
  cin >> n >> k >> x;
  priority_queue<int> pq;
  rep(i, n) {
    int a;
    cin >> a;
    pq.push(a);
  }

  while (k) {
    if (pq.empty()) break;
    int a = pq.top();
    pq.pop();

    if (a <= x)
      k--;
    else {
      int v = a / x;
      pq.push(a - min(k, v) * x);
      k -= min(k, v);
    }
  }

  ll ans = 0;
  while (!pq.empty()) {
    ans += pq.top();
    pq.pop();
  }

  cout << ans << endl;
}
