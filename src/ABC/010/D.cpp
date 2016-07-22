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

class MaximumFlow {
private:
    static const int INF = 1 << 29;

    class Edge {
    public:
        int to, cap, rev;
        Edge() {}
        Edge(int t, int c, int r) {
            to = t, cap = c, rev = r;
        }
    };

    int vertexSize;
    vector<int> level; // sからの距離
    vector<int> iter; // どこまで調べ終わったか
    vector<vector<Edge>> edge;

    void bfs(int s) {
        level = vector<int>(vertexSize, -1);
        queue<int> Q;
        level[s] = 0;
        Q.emplace(s);
        while (!Q.empty()) {
            int v = Q.front();
            Q.pop();
            for (int i = 0; i < (int)(edge[v].size()); i++) {
                Edge &e = edge[v][i];
                if (e.cap > 0 && level[e.to] < 0) {
                    level[e.to] = level[v] + 1;
                    Q.emplace(e.to);
                }
            }
        }
    }

    int dfs(int v, int t, int f) {
        if (v == t) return f;
        for (int &i = iter[v]; i < (int)(edge[v].size()); i++) {
            Edge &e = edge[v][i];
            if (e.cap > 0 && level[v] < level[e.to]) {
                int d = dfs(e.to, t, min(f, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    edge[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

public:
    MaximumFlow(int vs) {
        vertexSize = vs;
        level = vector<int>(vs);
        iter = vector<int>(vs);
        edge = vector<vector<Edge>>(vs);
    }

    void addEdge(int from, int to, int cap) {
        edge[from].emplace_back(Edge(to, cap, edge[to].size()));
        edge[to].emplace_back(Edge(from, cap, edge[from].size() - 1));
    }

    int getMaximumFlow(int s, int t) {
        int flow = 0;
        while (1) {
            bfs(s);
            if (level[t] < 0) break;
            iter = vector<int>(vertexSize, 0);
            int f;
            while ((f = dfs(s, t, INF)) > 0) {
                flow += f;
            }
        }
        return flow;
    }
};

int main() {
    int N, G, E;
    cin >> N >> G >> E;

    MaximumFlow mf(N + 1);

    rep (i, G) {
        int p;
        cin >> p;
        mf.addEdge(p, N, 1);
    }

    rep (i, E) {
        int a, b;
        cin >> a >> b;
        mf.addEdge(a, b, 1);
    }

    cout << mf.getMaximumFlow(0, N) << endl;
}
