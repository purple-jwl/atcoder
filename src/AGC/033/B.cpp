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
  map<char, int> dir;
  dir['U'] = 0;
  dir['R'] = 1;
  dir['D'] = 2;
  dir['L'] = 3;

  int h, w, n;
  cin >> h >> w >> n;
  int sr, sc;
  cin >> sr >> sc;
  string s, t;
  cin >> s >> t;

  vector<int> cnt(4, 0);
  int u = sr;
  int r = w - sc + 1;
  int d = h - sr + 1;
  int l = sc;
  // cout << u << ' ' << r << ' ' << d << ' ' << l << endl;
  rep(i, n) {
    cnt[dir[s[i]]]++;
    bool fin = false;
    if (cnt[0] == u) fin = true;
    if (cnt[1] == r) fin = true;
    if (cnt[2] == d) fin = true;
    if (cnt[3] == l) fin = true;

    if (fin) {
      cout << "NO" << endl;
      return 0;
    }

    cnt[(dir[t[i]] + 2) % 4]--;
    if (cnt[0] < 0 && (abs(cnt[0]) == d)) cnt[0]++;
    if (cnt[1] < 0 && (abs(cnt[1]) == l)) cnt[1]++;
    if (cnt[2] < 0 && (abs(cnt[2]) == u)) cnt[2]++;
    if (cnt[3] < 0 && (abs(cnt[3]) == r)) cnt[3]++;
  }

  cout << "YES" << endl;
}
