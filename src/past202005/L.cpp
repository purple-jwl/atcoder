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

vector<int> T[100000];
int idx[100000];
int pushed[100000];

int main() {
  int N;
  cin >> N;

  priority_queue<pii> one, two;

  rep(i, N) {
    int k;
    cin >> k;

    rep(j, k) {
      int t;
      cin >> t;
      T[i].eb(t);
      if (j == 1) {
        two.push(mp(t, i));
        pushed[i] = t;
      }
      if (j == 0) {
        one.push(mp(t, i));
      }
    }

    idx[i] = min(2, k);
  }

  int M;
  cin >> M;
  map<int, int> used;

  rep(i, M) {
    int a;
    cin >> a;

    if (a == 1) {
      pii p = one.top();
      one.pop();

      cout << p.F << endl;

      if (pushed[p.S] != -1) {
        one.push(mp(pushed[p.S], p.S));
        used[pushed[p.S]] = 1;
      }

      if (idx[p.S] < T[p.S].size()) {
        two.push(mp(T[p.S][idx[p.S]], p.S));
        pushed[p.S] = T[p.S][idx[p.S]];
        idx[p.S]++;
      } else {
        pushed[p.S] = -1;
      }
    } else {
      while (!two.empty() && used[two.top().F]) two.pop();

      if (two.empty() || (one.top().F > two.top().F)) {
        pii p = one.top();
        one.pop();

        cout << p.F << endl;

        if (pushed[p.S] != -1) {
          one.push(mp(pushed[p.S], p.S));
          used[pushed[p.S]] = 1;
        }
        if (idx[p.S] < T[p.S].size()) {
          two.push(mp(T[p.S][idx[p.S]], p.S));
          pushed[p.S] = T[p.S][idx[p.S]];
          idx[p.S]++;
        } else {
          pushed[p.S] = -1;
        }
      } else {
        pii p = two.top();
        two.pop();

        cout << p.F << endl;

        if (idx[p.S] < T[p.S].size()) {
          two.push(mp(T[p.S][idx[p.S]], p.S));
          pushed[p.S] = T[p.S][idx[p.S]];
          idx[p.S]++;
        } else {
          pushed[p.S] = -1;
        }
      }
    }
  }
}
