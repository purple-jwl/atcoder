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
  scanf("%d", &n);

  int ok = 0;
  int ng = n;
  while (abs(ok - ng) > 1) {
    int mid = (ok + ng) / 2;
    printf("? %d\n", mid);
    fflush(stdout);
    int res;
    scanf("%d", &res);
    if (res == 1)
      ng = mid;
    else
      ok = mid;
  }
  printf("! %d\n", ok);
  fflush(stdout);
}
