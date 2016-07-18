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

// R = 900, G = 1000, B = 1100
int dp[2000 + 5][1000 + 5];

int main() {
    int r, g, b;
    cin >> r >> g >> b;

    rep (i, 2000 + 5) rep(j, 1000 + 5) {
        dp[i][j] = INF;
    }
    dp[0][r + g + b] = 0;

    for (int i = 0; i < 2000; i++) {
        for (int j = r + g + b; j >= 0; j--) {
            if (dp[i][j] == INF) continue;
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
            if (j == 0) continue;
            int cost = 0;
            if (j > g + b) cost = abs(i - 900);
            else if (j > b) cost = abs(i - 1000);
            else cost = abs(i - 1100);
            dp[i + 1][j - 1] = min(dp[i + 1][j - 1], dp[i][j] + cost);
        }
    }

    cout << dp[2000][0] << endl;
}
