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

int red[100000];
int write[100000];

int main() {
    int n, m;
    cin >> n >> m;

    red[0] = 1;
    REP (i, 1, n) write[i] = 1;

    rep (i, m) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        if (write[x] != 0) {
            write[x]--;
            if (red[x] != 0) red[y]++;
            else write[y]++;
        } else {
            red[x]--;
            red[y]++;
        }
    }

    int ans = 0;
    rep (i, n) if (red[i]) ans++;

    cout << ans << endl;
}
