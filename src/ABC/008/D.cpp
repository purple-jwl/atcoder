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

map<vector<int>, int> memo;

int rec(int x0, int y0, int x1, int y1, vector<int> x, vector<int> y) {
    vector<int> p{x0, y0, x1, y1};

    if (memo.find(p) != memo.end()) return memo[p];

    int res = 0;

    rep (i, sz(x)) {
        if (!(x0 <= x[i] && x[i] <= x1)) continue;
        if (!(y0 <= y[i] && y[i] <= y1)) continue;

        int sum = (x[i] - x0) + (x1 - x[i]) + (y[i] - y0) + (y1 - y[i]) + 1;

        if (x0 < x[i] && y0 < y[i]) {
            sum += rec(x0, y0, x[i] - 1, y[i] - 1, x, y);
        }
        if (x[i] < x1 && y[i] < y1) {
            sum += rec(x[i] + 1, y[i] + 1, x1, y1, x, y);
        }
        if (x0 < x[i] && y[i] < y1) {
            sum += rec(x0, y[i] + 1, x[i] - 1, y1, x, y);
        }
        if (x[i] < x1 && y0 < y[i]) {
            sum += rec(x[i] + 1, y0, x1, y[i] - 1, x, y);
        }

        res = max(res, sum);
    }

    return memo[p] = res;
}

int main() {
    int w, h, n;
    cin >> w >> h >> n;
    vector<int> x(n), y(n);
    rep (i, n) {
        cin >> x[i] >> y[i];
        x[i]--;
        y[i]--;
    }
    cout << rec(0, 0, w - 1, h - 1, x, y) << endl;
}
