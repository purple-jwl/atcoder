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

class LowestCommonAncestor {
private:
    int vertexSize;
    int logVertexSize = 31;
    vector<int> depth;
    vector<vector<int>> edge;
    vector<vector<int>> parent; // 親を2^k回たどって到達する頂点

    void dfs(int curr, int prev, int d) {
        parent[0][curr] = prev;
        depth[curr] = d;
        for (int i = 0; i < edge[curr].size(); i++) {
            if (edge[curr][i] != prev) dfs(edge[curr][i], curr, d + 1);
        }
    }

public:
    LowestCommonAncestor(int vs) {
        vertexSize = vs;
        depth = vector<int>(vs);
        edge = vector<vector<int>>(vs);
        parent = vector<vector<int>>(31, vector<int>(vs));
    }

    void addEdge(int u, int v) {
        edge[u].emplace_back(v);
    }

    void setup(int root) {
        // parent[0]とdepthを初期化
        dfs(root, -1, 0);

        // parentを初期化
        for (int k = 0; k < logVertexSize - 1; k++) {
            for (int i = 0; i < vertexSize; i++) {
                parent[k + 1][i] = (parent[k][i] < 0) ? -1 : parent[k][parent[k][i]];
            }
        }
    }

    int getLowestCommonAncestor(int u, int v) {
        if (depth[u] > depth[v]) swap(u, v);
        for (int k = 0; k < logVertexSize - 1; k++) {
            if (((depth[v] - depth[u]) >> k) & 1) v = parent[k][v];
        }
        if (u == v) return u;
        for (int k = logVertexSize - 1; k >= 0; k--) {
            if (parent[k][u] != parent[k][v]) {
                u = parent[k][u];
                v = parent[k][v];
            }
        }
        return parent[0][u];
    }

    int getDepth(int u) {
        return depth[u];
    }

    int getDistance(int u, int v) {
        int lca = getLowestCommonAncestor(u, v);
        return depth[u] + depth[v] - 2 * depth[lca];
    }
};

int main() {
    int n;
    cin >> n;

    LowestCommonAncestor lca(n);

    rep (i, n - 1) {
        int x, y;
        cin >> x >> y;
        lca.addEdge(x - 1, y - 1);
        lca.addEdge(y - 1, x - 1);
    }

    lca.setup(0);

    int q;
    cin >> q;
    rep (i, q) {
        int a, b;
        cin >> a >> b;
        int ans = lca.getDistance(a - 1, b - 1) + 1;
        cout << ans << endl;
    }
}
