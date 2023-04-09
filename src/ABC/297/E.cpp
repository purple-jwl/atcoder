#include <bits/stdc++.h>

#define REP(i, x, n) for (int i = x; i < (int)(n); i++)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define uniq(x) x.erase(unique(x.begin(), x.end()), x.end())

using namespace std;

typedef long long ll;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  rep(i, N) cin >> A[i];
  uniq(A);

  priority_queue<ll, vector<ll>, greater<ll>> pq;
  map<ll, int> cnt;
  rep(i, A.size()) {
    ll v = 0;
    rep(j, K) {
      v += A[i];
      pq.push(v);
      cnt[v] = 1;
    }
  }

  ll ans = 0;
  rep(i, K) {
    ans = pq.top();
    while (!pq.empty() && ans == pq.top()) pq.pop();
    rep(j, A.size()) if (cnt[ans + A[j]] == 0) {
      cnt[ans + A[j]] = 1;
      pq.push(ans + A[j]);
    }
  }

  cout << ans << endl;
}
