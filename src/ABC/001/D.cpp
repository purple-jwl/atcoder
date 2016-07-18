#include <bits/stdc++.h>

#define REP(i, x, n) for (int i = x; i < (int)(n); i++)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x.size())
#define uniq(x) x.erase(unique(x.begin(), x.end()), x.end())
#define F first
#define S second
#define mp make_pair
#define eb emplace_back

using namespace std;

typedef long long ll;

const int INF = 1 << 30;

int main() {
    vector<int> table(2500);
    int n, s, e;
    cin >> n;

    rep (i, n) {
        scanf("%d-%d", &s, &e);
        if (s % 5 != 0) {
            s = s - s % 5;
        }
        if (e % 5 != 0) {
            e = e - e % 5 + 5;
            if (e % 100 == 60) {
                e += 40;
            }
        }
        table[s]++;
        table[e]--;
    }

    int cnt = 0;
    s = -1;
    rep (i, 2500) {
        if (table[i] != 0) {
            cnt += table[i];
            if (cnt != 0 && s == -1) {
                s = i;
            }
            if (cnt == 0) {
                printf("%04d-%04d\n", s, i);
                s = -1;
            }
        }
    }

    return 0;
}
