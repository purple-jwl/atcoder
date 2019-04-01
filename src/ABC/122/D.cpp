#include <iostream>

using namespace std;

const int mod = 1000000007;

// a=0, c=1, g=2, t=3
long long dp[101][5][5][5];

int main() {
  int n;
  cin >> n;

  dp[0][4][4][4] = 1;

  for (int p = 0; p < n; p++) {
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
        for (int k = 0; k < 5; k++) {
          if (dp[p][i][j][k] == 0) continue;
          for (int q = 0; q < 4; q++) {
            if (j == 0 && k == 2 && q == 1) continue;
            if (j == 2 && k == 0 && q == 1) continue;
            if (j == 0 && k == 1 && q == 2) continue;
            if (i == 0 && k == 2 && q == 1) continue;
            if (i == 0 && j == 2 && q == 1) continue;
            dp[p + 1][j][k][q] += dp[p][i][j][k];
            dp[p + 1][j][k][q] %= mod;
          }
        }
      }
    }
  }

  long long ans = 0;

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      for (int k = 0; k < 5; k++) {
        ans += dp[n][i][j][k];
        ans %= mod;
      }
    }
  }

  cout << ans << endl;

  return 0;
}
