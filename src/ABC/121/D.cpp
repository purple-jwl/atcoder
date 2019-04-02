#include <iostream>

using namespace std;

long long f(long long v) {
  if (v % 4 == 0) return v;
  if (v % 4 == 1) return 1;
  if (v % 4 == 2) return v + 1;
  if (v % 4 == 3) return 0;
}

int main() {
  long long A, B;
  cin >> A >> B;
  cout << (f(B) ^ f(A ? A - 1 : A)) << endl;
  return 0;
}
