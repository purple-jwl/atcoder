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
  ll N, A, B;
  cin >> N >> A >> B;
  ll ans = 0;
  if ((B - A) % 2) {
    if (A - 1 < N - B) {
      ans += A - 1;
      B -= A - 1;
      A = 1;
      if ((B - A) % 2) {
        ans++;
        B--;
      }
    } else {
      ans += (N - B);
      A += (N - B);
      B = N;
      if ((B - A) % 2) {
        ans++;
        A++;
      }
    }
  }

  ans += B - (B + A) / 2;

  cout << ans << endl;
}
