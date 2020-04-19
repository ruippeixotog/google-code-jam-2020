#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>

#define MAXN 2000
#define INF 0x3f3f3f3f

using namespace std;

typedef long long ll;
typedef long double ld;

int x[MAXN], y[MAXN];

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    int x, y; scanf("%d %d\n", &x, &y);

//    int xLeft = abs(x), yLeft = abs(y);
    int sum = 1, curr = 1;
    while(sum < abs(x) + abs(y)) {
      curr *= 2;
      sum += curr;
    }
    string sol;
    while(curr > 0) {
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
//      cerr << "curr " << curr << " x " << x << " y " << y << endl;
      curr /= 2;
    }
    reverse(sol.begin(), sol.end());
    printf("Case #%d: %s\n", tc, x == 0 && y == 0 ? sol.c_str() : "IMPOSSIBLE");
  }
  return 0;
}
