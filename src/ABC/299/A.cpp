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
  string s = "";
  cin >> n;
  rep(i, n) {
    char c;
    cin >> c;
    if (c != '.') s += c;
  }
  cout << (s == "|*|" ? "in" : "out") << endl;
}
