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
typedef vector<vector<ll>> Matrix;

const int INF = 1 << 29;

Matrix mul(Matrix A, Matrix B) {
    Matrix C(sz(A), vector<ll>(sz(B[0]), 0));

    rep (i, sz(A)) rep (j, sz(B[0])) rep (k, sz(A[0])) {
        C[i][j] ^= (A[i][k] & B[k][j]);
    }

    return C;
}

Matrix pow(Matrix A, ll n) {
    Matrix res(sz(A), vector<ll>(sz(A), 0));

    rep (i, sz(A)) res[i][i] = -1;

    while (n > 0) {
        if (n & 1) res = mul(res, A);
        A = mul(A, A);
        n >>= 1;
    }

    return res;
}

int main() {
    ll K, M;
    cin >> K >> M;

    Matrix A(K, vector<ll>(1));
    Matrix mat(K, vector<ll>(K));
    rep (i, K) cin >> A[K - i - 1][0];
    rep (i, K) cin >> mat[0][i];
    REP (i, 1, K) REP (j, 0, K) {
        mat[i][j] = (i - 1 == j) ? -1 : 0;
    }

    mat = pow(mat, M - 1);
    Matrix ans = mul(mat, A);

    cout << ans[K - 1][0] << endl;
}
