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

const double EPS = 1e-9;

// (x, y) = (Point.real(), Point.imag())
typedef complex<double> Point;

// 内積
double dot(Point a, Point b) {
    return a.real() * b.real() + a.imag() * b.imag();
}

// 外積
double cross(Point a, Point b) {
    return a.real() * b.imag() - b.real() * a.imag();
}

// ベクトルp1p2に対する点p3の位置関係
int ccw(Point p1, Point p2, Point p3) {
    Point a = p2 - p1;
    Point b = p3 - p1;
    if (cross(a, b) > EPS)  return +1; // counter clockwise
    if (cross(a, b) < -EPS) return -1; // clockwise
    if (dot(a, b) < -EPS)   return +2; // online back
    if (norm(a) < norm(b))  return -2; // online front
    return 0;                          // on segment
}

// 線分と線分の交差判定
bool isIntersectionSS(Point p1, Point p2, Point p3, Point p4) {
    return (ccw(p1 ,p2, p3) * ccw(p1, p2, p4) <= 0)
        && (ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0);
}

int main() {
    int x, y;
    cin >> x >> y;
    Point A(x, y);
    cin >> x >> y;
    Point B(x, y);

    int N;
    vector<Point> vp;
    cin >> N;
    rep (i, N) {
        cin >> x >> y;
        vp.eb(Point(x, y));
    }

    int cnt = 0;
    rep (i, N) {
        int j = (i + 1) % N;
        if (isIntersectionSS(A, B, vp[i], vp[j])) cnt++;
    }

    cout << cnt / 2 + 1 << endl;
}
