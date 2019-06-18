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
// const int MOD = 1000000007;

ll nCr[51][51];

int main() {
  nCr[0][0] = 1;
  rep (i, 50) rep (j, i + 1) {
    nCr[i + 1][j] += nCr[i][j];
    if (j + 1 <= 50) nCr[i + 1][j + 1] += nCr[i][j];
  }

  int N, A, B;
  cin >> N >> A >> B;

  vector<ll> v(N);
  map<ll, int> cnt;
  rep (i, N) {
    cin >> v[i];
    cnt[v[i]]++;
  }

  sort(rall(v));
  uniq(v);

  double sum = 0;
  int d = 0;
  ll c = 0;

  rep (i, v.size()) {
    if (d + cnt[v[i]] < A) {
      sum += v[i] * cnt[v[i]];
      d += cnt[v[i]];
    } else {
      if (d == 0) {
        sum = v[i];
        d = 1;
        REP (j, A, B + 1) {
          c += nCr[cnt[v[0]]][j];
        }
      } else {
        c = nCr[cnt[v[i]]][A - d];
        sum += v[i] * (A - d);
        d = A;
      }
      break;
    }
  }

  printf("%.10f\n", sum / d);
  cout << c << endl;
}
