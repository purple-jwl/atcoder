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
const ll MOD = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> f(n);
    rep (i, n) cin >> f[i];

    vector<int> cnt(m + 1, 0);
    vector<ll> dp(n + 1, 0);
    dp[0] = 1;

    int l = 0;
    ll sum = 0;
    rep (r, n) {
        sum = (sum + dp[r]) % MOD;
        if (++cnt[f[r]] == 2) {
            while (1) {
                cnt[f[l]]--;
                sum = (sum - dp[l] + MOD) % MOD;
                if (f[l++] == f[r]) break;
            }
        }
        dp[r + 1] = sum;
    }

    cout << dp[n] << endl;
}
