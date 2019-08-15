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

int main() {
  int n;
  cin >> n;
  vector<int> a1(n), a2(n), a3(n);
  rep(i, n) cin >> a1[i];
  rep(i, n) cin >> a2[i];
  rep(i, n) cin >> a3[i];

  vector<ll> lmax(n + 1, 0);
  priority_queue<int, vector<int>, greater<int>> pq1;
  rep(i, n) {
    lmax[0] += a1[i];
    pq1.push(a1[i]);
  }
  rep(i, n) {
    lmax[i + 1] = lmax[i];
    pq1.push(a2[i]);
    lmax[i + 1] += a2[i];
    int m = pq1.top();
    pq1.pop();
    lmax[i + 1] -= m;
  }

  vector<ll> rmin(n + 1, 0);
  priority_queue<int> pq3;
  rep(i, n) {
    rmin[0] += a3[i];
    pq3.push(a3[i]);
  }
  rep(i, n) {
    rmin[i + 1] = rmin[i];
    pq3.push(a2[n - 1 - i]);
    rmin[i + 1] += a2[n - 1 - i];
    int m = pq3.top();
    pq3.pop();
    rmin[i + 1] -= m;
  }

  ll ans = lmax[0] - rmin[0];
  rep(i, n + 1) ans = max(ans, lmax[i] - rmin[n - i]);

  cout << ans << endl;
}
