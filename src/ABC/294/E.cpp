#include <bits/stdc++.h>

#define REP(i, x, n) for (int i = x; i < (int)(n); i++)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
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
  ll L, N1, N2;
  cin >> L >> N1 >> N2;

  vector<ll> v1(N1), l1(N1), v2(N2), l2(N2);
  rep(i, N1) cin >> v1[i] >> l1[i];
  rep(i, N2) cin >> v2[i] >> l2[i];

  ll ans = 0, sum1 = 0, sum2 = 0;
  int idx1 = 0, idx2 = 0, c1 = 0, c2 = 0;

  while (!(sum1 == L && sum2 == L)) {
    if (sum1 <= sum2) {
      if (v1[idx1] == c2) {
        ans += min(sum2 - sum1, l1[idx1]);
      }
      sum1 += l1[idx1];
      c1 = v1[idx1];
      idx1++;
    } else {
      if (v2[idx2] == c1) {
        ans += min(sum1 - sum2, l2[idx2]);
      }
      sum2 += l2[idx2];
      c2 = v2[idx2];
      idx2++;
    }
  }

  cout << ans << endl;
}
