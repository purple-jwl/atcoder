#include <bits/stdc++.h>

#define REP(i, x, n) for (int i = x; i < (int)(n); i++)
#define rep(i, n) REP(i, 0, n)
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
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

typedef long long ll;

/* --- INFやMODの値が適切か確認する --- */
// const int INF = 1 << 30;
// const ll INF = 1LL << 60;
// const ll MOD = 1000000007;

int main() {
  vector<int> cnt(10, 0);
  string s;
  cin >> s;
  rep(i, s.size()) cnt[s[i] - '0']++;

  if (s.size() < 3) {
    bool f = stoi(s) % 8 == 0;
    reverse(all(s));
    f |= stoi(s) % 8 == 0;
    cout << (f ? "Yes" : "No") << endl;
    return 0;
  }

  REP(i, 1, 10) REP(j, 1, 10) REP(k, 1, 10) {
    int v = i * 100 + j * 10 + k;
    if (v % 2 == 0 && ((v / 2) % 100 % 4) == 0) {
      vector<int> c(10, 0);
      c[i]++;
      c[j]++;
      c[k]++;
      bool f = true;
      REP(l, 1, 10) if (cnt[l] < c[l]) f = false;
      if (f) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }

  cout << "No" << endl;
}
