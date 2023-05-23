#include <bits/stdc++.h>

#define REP(i, x, n) for (int i = x; i < (int)(n); i++)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define uniq(x) x.erase(unique(x.begin(), x.end()), x.end())

using namespace std;

typedef long long ll;

typedef pair<int, int> P;

int main() {
  int n;
  cin >> n;
  vector<P> ab;
  rep(i, n) {
    int a, b;
    cin >> a >> b;
    ab.push_back(make_pair(a, 1));
    ab.push_back(make_pair(a + b, -1));
  }
  sort(all(ab));

  vector<int> ans(n + 1, 0);
  int cnt = 0;
  rep(i, ab.size() - 1) {
    cnt += ab[i].second;
    ans[cnt] += ab[i + 1].first - ab[i].first;
  }

  REP(i, 1, n + 1) cout << ans[i] << ' ';
  cout << endl;
}
