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

const int INF = 1 << 30;

ll dp[20][2][2]; // dp[桁][未満][4,9を含む]

ll func(ll num) {
    string s = to_string(num);
    int len = s.size();

    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1;

    rep (i, len) rep (j, 2) rep (k, 2) {
        int d = j ? 9 : s[i] - '0';
        rep (p, d + 1) {
            dp[i + 1][j | (int)(p < d)][k | (int)(p == 4) | (int)(p == 9)] += dp[i][j][k];
        }
    }

    return dp[len][0][1] + dp[len][1][1];
}

int main() {
    ll A, B;
    cin >> A >> B;
    cout << func(B) - func(A - 1) << endl;
}
