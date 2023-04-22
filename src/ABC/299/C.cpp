#include <bits/stdc++.h>

#define REP(i, x, n) for (int i = x; i < (int)(n); i++)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define uniq(x) x.erase(unique(x.begin(), x.end()), x.end())

using namespace std;

typedef long long ll;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int ans = -1;
  int cnt = 0;
  rep(i, n) {
    while (i < n && s[i] == 'o') cnt++, i++;
    if (cnt != n && cnt > 0) ans = max(ans, cnt);
    cnt = 0;
  }
  cout << ans << endl;
}
