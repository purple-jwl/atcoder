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

// const int INF = 1 << 30;
// const ll INF = 1LL << 60;
// const int MOD = 1000000007;

int main() {
  string s;
  cin >> s;
  int a = (s[0] - '0') * 10 + (s[1] - '0');
  int b = (s[2] - '0') * 10 + (s[3] - '0');
  if (1 <= a && a <= 12 && 1 <= b && b <= 12) cout << "AMBIGUOUS" << endl;
  else if (1 <= a && a <= 12) cout << "MMYY" << endl;
  else if (1 <= b && b <= 12) cout << "YYMM" << endl;
  else cout << "NA" << endl;
}
