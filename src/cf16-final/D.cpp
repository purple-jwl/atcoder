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

/* --- INFの値が適切か確認する --- */
// const int INF = 1 << 30;
// const ll INF = 1LL << 60;
// const int MOD = 1000000007;

vector<int> vi[100001];
int cnt[100001];
int modCnt[100001];

int main() {
  int N, M;
  cin >> N >> M;

  rep(i, N) {
    int X;
    cin >> X;
    cnt[X]++;
  }

  rep(i, 100001) if (cnt[i]) {
    modCnt[i % M] += cnt[i];
    vi[i % M].eb(cnt[i]);
  }

  int ans = 0;
  rep(i, M) {
    int j = (M - i) % M;
    if (i > j) break;

    int cnt1 = modCnt[i], cnt2 = modCnt[j];
    vector<int> v1 = vi[i], v2 = vi[j];
    sort(rall(v1));
    sort(rall(v2));

    if (cnt1 < cnt2) {
      swap(v1, v2);
      swap(cnt1, cnt2);
    }

    if (i == j) {
      ans += cnt1 / 2;
    } else {
      int idx = 0;
      while (1) {
        if (idx >= v1.size() || v1[idx] <= 1) break;

        if ((cnt1 - (v1[idx] / 2) * 2) < cnt2) {
          ans += (cnt1 - cnt2) / 2;
          break;
        }

        ans += v1[idx] / 2;
        cnt1 -= (v1[idx] / 2) * 2;
        idx++;
      }
      ans += cnt2;
    }
  }

  cout << ans << endl;
}
