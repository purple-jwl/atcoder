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
const ll MOD = 998244353;

ll dp[300000][2];

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];

    dp[0][0] = dp[0][1] = 1;
    REP (i, 1, n) {
        if (a[i] != a[i - 1]) dp[i][0] = (dp[i][0] + dp[i - 1][0]) % MOD;
        if (a[i] != b[i - 1]) dp[i][0] = (dp[i][0] + dp[i - 1][1]) % MOD;
        if (b[i] != a[i - 1]) dp[i][1] = (dp[i][1] + dp[i - 1][0]) % MOD;
        if (b[i] != b[i - 1]) dp[i][1] = (dp[i][1] + dp[i - 1][1]) % MOD;
    }

    cout << (dp[n - 1][0] + dp[n - 1][1]) % MOD << endl;
}
