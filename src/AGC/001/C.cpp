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

vector<int> edge[2000];

int dfs(int curr, int prev, int dist) {
    if (dist == 0) return 1;

    int res = 1;
    rep (i, sz(edge[curr])) {
        if (edge[curr][i] != prev) {
            res += dfs(edge[curr][i], curr, dist - 1);
        }
    }

    return res;
}

int main() {
    int n, k;
    cin >> n >> k;
    rep (i, n - 1) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        edge[a].eb(b);
        edge[b].eb(a);
    }

    int ans = INF;

    if (k % 2) {
        rep (i, n) rep (j, sz(edge[i])) {
            int tmp = n - dfs(i, edge[i][j], k / 2) - dfs(edge[i][j], i, k / 2);
            ans = min(ans, tmp);
        }
    } else {
        rep (i, n) {
            ans = min(ans, n - dfs(i, -1, k / 2));
        }
    }

    cout << ans << endl;
}
