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

int tmp[200005];
int to[200005][31];
int ans[200005];

int main() {
    int n, m, d;
    cin >> n >> m >> d;

    rep (i, n) tmp[i] = i;

    rep (i, m) {
        int a;
        cin >> a;
        swap(tmp[a - 1], tmp[a]);
    }

    rep (i, n) {
        to[tmp[i]][0] = i;
    }

    REP (j, 1, 31) rep (i, n) {
        to[i][j] = to[to[i][j - 1]][j - 1];
    }

    rep (i, n) {
        int dd = d;
        int idx = i;
        for (int j = 30; j >= 0; j--) {
            if ((dd >> j) & 1) {
                idx = to[idx][j];
                dd ^= (1 << j);
            }
        }
        cout << idx + 1 << endl;
    }
}
