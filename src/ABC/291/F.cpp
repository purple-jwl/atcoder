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
const int INF = 1 << 29;
// const ll INF = 1LL << 60;
// const ll MOD = 1000000007;

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    rep (i, n) cin >> s[i];

    vector<int> dp1(n, INF), dp2(n, INF);

    dp1[0] = 0;
    rep (i, n) rep (j, m) if (s[i][j] == '1') {
        dp1[i + j + 1] = min(dp1[i + j + 1], dp1[i] + 1);
    }

    dp2[n - 1] = 0;
    for (int i = n - 1; i >= 0; i--) rep (j, m) {
        int k = i - j - 1;
        if (k >= 0 && s[k][j] == '1') dp2[k] = min(dp2[k], dp2[i] + 1);
    }

    // rep (i, n) cout << dp1[i] << ' ';
    // cout << endl;
    // rep (i, n) cout << dp2[i] << ' ';
    // cout << endl;

    REP (k, 1, n - 1) {
        if (k != 1) cout << ' ';

        int ans = INF;
        REP (i, max(0, k - m + 1), k) rep (a, m) if (s[i][a] == '1') {
            int j = i + 1 + a;
            if (i < k && k < j) ans = min(ans, dp1[i] + dp2[j] + 1);
        }
        if (ans == INF) ans = -1;

        cout << ans;
    }
    cout << endl;
}
