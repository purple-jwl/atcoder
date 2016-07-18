#include <bits/stdc++.h>

#define REP(i, x, n) for (int i = x; i < (int)(n); i++)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x.size())
#define uniq(x) x.erase(unique(x.begin(), x.end()), x.end())
#define F first
#define S second
#define mp make_pair
#define eb emplace_back

using namespace std;

typedef long long ll;

const int INF = 1 << 30;

int D[50][50];
int sum[50][50];
int ans[50 * 50 + 5];

void solve(int n) {
    rep (i, n) rep (j, n) {
        int s = D[i][j];
        if (i - 1 >= 0) {
            s += sum[i - 1][j];
        }
        if (j - 1 >= 0) {
            s += sum[i][j - 1];
        }
        if (i - 1 >= 0 && j - 1 >= 0) {
            s -= sum[i - 1][j - 1];
        }
        sum[i][j] = s;
    }

    rep (i, n) rep (j, n) {
        REP (ii, i, n) REP (jj, j, n) {
            int s = sum[ii][jj];
            if (i - 1 >= 0) {
                s -= sum[i - 1][jj];
            }
            if (j - 1 >= 0) {
                s -= sum[ii][j - 1];
            }
            if (i - 1 >= 0 && j - 1 >= 0) {
                s += sum[i - 1][j - 1];
            }
            int r = ii - i + 1;
            int c = jj - j + 1;
            ans[r * c] = max(ans[r * c], s);
        }
    }

    REP (i, 1, n * n + 1) {
        ans[i] = max(ans[i - 1], ans[i]);
    }
}

int main() {
    int n;
    cin >> n;

    rep (i, n) rep (j, n) {
        cin >> D[i][j];
    }

    solve(n);

    int q;
    cin >> q;

    rep (i, q) {
        int p;
        cin >> p;
        cout << ans[p] << endl;
    }
}
