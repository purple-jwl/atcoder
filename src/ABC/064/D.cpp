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
  int N;
  cin >> N;
  string S;
  cin >> S;

  string ans = "";
  int openCnt = 0;
  int closeCnt = 0;

  for (int i = N - 1; i >= 0; i--) {
    if (S[i] == ')') {
      closeCnt++;
      ans = ")" + ans;
    }
    if (S[i] == '(') {
      openCnt++;
      ans = "(" + ans;
      if (openCnt > closeCnt) {
        closeCnt++;
        ans += ")";
      }
    }
  }

  while (openCnt != closeCnt) {
    openCnt++;
    ans = "(" + ans;
  }

  cout << ans << endl;
}
