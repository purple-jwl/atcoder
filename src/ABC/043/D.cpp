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

    if (s.size() == 2 && s[0] == s[1]) {
        cout << "1 2" << endl;
        return 0;
    }

    rep (i, s.size() - 2) {
        set<char> sc;
        sc.insert(s[i]);
        sc.insert(s[i + 1]);
        sc.insert(s[i + 2]);
        if (sc.size() < 3) {
            cout << i + 1 << ' ' << i + 3 << endl;
            return 0;
        }
    }

    cout << "-1 -1" << endl;
    return 0;
}
