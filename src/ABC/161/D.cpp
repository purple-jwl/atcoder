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
  int k;
  cin >> k;
  vector<ll> v;

  queue<ll> Q;
  rep(i, 9) Q.push(i + 1);

  while (v.size() != k) {
    ll a = Q.front();
    Q.pop();

    v.eb(a);

    int m = a % 10;
    if (m > 0) Q.push(a * 10 + m - 1);
    Q.push(a * 10 + m);
    if (m < 9) Q.push(a * 10 + m + 1);
  }

  cout << v[k - 1] << endl;
}
