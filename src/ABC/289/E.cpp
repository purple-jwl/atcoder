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
const int INF = 1 << 30;
// const ll INF = 1LL << 60;
// const ll MOD = 1000000007;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<int> c(n);
        rep (i, n) cin >> c[i];

        vector<int> edge[n];
        rep (i, m) {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            edge[u].eb(v);
            edge[v].eb(u);
        }

        int dist[n][n];
        rep (i, n) rep (j, n) dist[i][j] = INF;
        dist[0][n - 1] = 0;

        int ans = -1;
        queue<pii> Q;
        Q.push(mp(0, n - 1));

        while (!Q.empty()) {
            int u = Q.front().F;
            int v = Q.front().S;
            Q.pop();

            rep (i, edge[u].size()) rep (j, edge[v].size()) {
                int un = edge[u][i];
                int vn = edge[v][j];
                if (c[un] == c[vn]) continue;
                if (dist[un][vn] <= dist[u][v] + 1) continue;
                dist[un][vn] = dist[u][v] + 1;
                Q.push(mp(un, vn));
                if (un == n - 1 && vn == 0) ans = dist[un][vn];
            }

            if (ans != -1) break;
        }

        cout << ans << endl;
    }
}
