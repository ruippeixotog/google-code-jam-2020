#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    int x, y; scanf("%d %d\n", &x, &y);
    string m; cin >> m;

    int res = -1;
    for(int i = 0; i < m.size(); i++) {
      switch(m[i]) {
        case 'N': y++; break;
        case 'S': y--; break;
        case 'E': x++; break;
        case 'W': x--; break;
      }
      if(abs(x) + abs(y) <= i + 1) {
        res = i + 1;
        break;
      }
    }
    if(res == -1) printf("Case #%d: IMPOSSIBLE\n", tc);
    else printf("Case #%d: %d\n", tc, res);
  }
  return 0;
}
