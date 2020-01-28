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

int cnt[100000 + 5][3];
int sum[100000 + 5];

int main() {
  int n;
  cin >> n;
  vector<int> r(n), h(n);
  rep(i, n) {
    cin >> r[i] >> h[i];
    h[i]--;
    cnt[r[i]][h[i]]++;
  }

  rep(i, 100001) {
    rep(j, 3) sum[i] += cnt[i][j];
    sum[i + 1] = sum[i];
  }

  rep(i, n) {
    int a, b, c;
    a = b = c = 0;
    if (r[i] - 1 >= 0) a = sum[r[i] - 1];
    a += cnt[r[i]][(h[i] + 1) % 3];
    b = cnt[r[i]][h[i]] - 1;
    c = cnt[r[i]][(h[i] + 2) % 3] + sum[100000] - sum[r[i]];

    cout << a << ' ' << c << ' ' << b << endl;
  }
}
