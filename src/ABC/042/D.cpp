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

const int INF = 1 << 29;
const ll MOD = 1e+9 + 7;

ll fact[200010];
ll inv[200010];
ll factInv[200010];

void init() {
    fact[0] = 1;
    REP (i, 1, 200010) fact[i] = fact[i - 1] * i % MOD;

    inv[1] = 1;
    REP (i, 2, 200010) inv[i] = inv[MOD % i] * (MOD - MOD / i) % MOD;

    factInv[0] = 1;
    REP (i, 1, 200010) factInv[i] = factInv[i - 1] * inv[i] % MOD;
}

ll modComb(int n, int r) {
    return fact[n] * factInv[n - r] % MOD * factInv[r] % MOD;
}

int main() {
    init();

    int H, W, A, B;
    cin >> H >> W >> A >> B;
    ll ans = 0;
    rep (i, H - A) {
        int h1 = i + 1;
        int w1 = B;
        int h2 = H - i;
        int w2 = W - B;
        ans = (ans + modComb(h1 + w1 - 2, w1 - 1) * modComb(h2 + w2 - 2, w2 - 1)) % MOD;
    }

    cout << ans << endl;
}
