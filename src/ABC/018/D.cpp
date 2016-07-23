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

int main() {
    int n, m, p, q, r;
    cin >> n >> m >> p >> q >> r;

    vector<pair<int, int>> edge[n];
    rep (i, r) {
        int x, y, z;
        cin >> x >> y >> z;
        edge[x - 1].eb(mp(y - 1, z));
    }

    int ans = 0;
    rep (i, (1 << n)) {
        if (popcount(i) != p) continue;
        vector<int> cnt(m);
        rep (j, n) {
            if ((i >> j) & 1) {
                rep (k, sz(edge[j])) {
                    pair<int, int> e = edge[j][k];
                    cnt[e.F] += e.S;
                }
            }
        }
        sort(rall(cnt));
        int sum = 0;
        rep (j, q) sum += cnt[j];

        ans = max(ans, sum);
    }

    cout << ans << endl;
}
