#include <bits/stdc++.h>

#define REP(i, x, n) for (int i = x; i < (int)(n); i++)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define uniq(x) x.erase(unique(x.begin(), x.end()), x.end())

using namespace std;

typedef long long ll;

const int MAX = 300000;

bool isPrime[MAX + 1];

void sieve(int N) {
  for (int i = 0; i <= N; i++) {
    isPrime[i] = true;
  }

  isPrime[0] = isPrime[1] = false;

  for (int i = 2; i <= N; i++) {
    if (!isPrime[i]) continue;
    for (int j = i + i; j <= N; j += i) {
      isPrime[j] = false;
    }
  }
}

int main() {
  // cout << sqrt(1000000000000 / (2 * 2 * 3)) << endl;
  sieve(MAX);

  vector<ll> prime;
  rep(i, MAX + 1) if (isPrime[i]) prime.push_back(i);
  int ps = prime.size();

  // cout << prime.size() << endl;

  int ans = 0;

  ll n;
  cin >> n;
  rep(i, ps) REP(j, i + 1, ps) REP(k, j + 1, ps) {
    ll v = prime[i] * prime[i] * prime[j];
    if (v > n) break;
    v *= prime[k];
    if (v > n) break;
    v *= prime[k];
    if (v > n) break;
    ans++;
  }

  cout << ans << endl;
}
