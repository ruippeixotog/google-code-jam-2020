#include <algorithm>
#include <cstdio>
#include <string>

using namespace std;

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    int x, y; scanf("%d %d\n", &x, &y);

    int sum = 1, curr = 1;
    while(sum < abs(x) + abs(y)) {
      curr *= 2;
      sum += curr;
    }
    string sol;
    for(; curr > 0; curr /= 2) {
      if(abs(x) > abs(y)) {
        if(x >= 0) {
          sol.push_back('E');
          x -= curr;
        } else {
          sol.push_back('W');
          x += curr;
        }
      } else {
        if(y >= 0) {
          sol.push_back('N');
          y -= curr;
        } else {
          sol.push_back('S');
          y += curr;
        }
      }
    }
    reverse(sol.begin(), sol.end());
    printf("Case #%d: %s\n", tc, x == 0 && y == 0 ? sol.c_str() : "IMPOSSIBLE");
  }
  return 0;
}
