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
  int n, w;
  cin >> n >> w;
  vector<ll> v(200000 + 5, 0);
  rep(i, n) {
    int s, t, p;
    cin >> s >> t >> p;
    v[s] += p;
    v[t] -= p;
  }

  rep(i, v.size() - 1) v[i + 1] += v[i];

  rep(i, v.size()) if (v[i] > w) {
    cout << "No" << endl;
    return 0;
  }

  cout << "Yes" << endl;
}
