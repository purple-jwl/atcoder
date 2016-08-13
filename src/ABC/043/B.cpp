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
    string s;
    cin >> s;
    vector<char> vc;

    rep (i, s.size()) {
        if (s[i] == 'B') {
            if (vc.size() != 0) {
                vc.pop_back();
            }
        } else {
            vc.eb(s[i]);
        }
    }

    rep (i, vc.size()) {
        cout << vc[i];
    }
    cout << endl;
}
