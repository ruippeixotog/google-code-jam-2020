#include <algorithm>
#include <cstdio>
#include <numeric>
#include <string>

#define MAXN 1000

using namespace std;

int s[MAXN], e[MAXN];

int order[MAXN];

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    int n; scanf("%d\n", &n);
    for(int i = 0; i < n; i++)
      scanf("%d %d\n", &s[i], &e[i]);

    iota(order, order + n, 0);
    sort(order, order + n, [](int o1, int o2) {
      return s[o1] < s[o2];
    });

    string res(n, '.');
    int cLast = 0, jLast = 0;
    for(int i = 0; i < n; i++) {
      int idx = order[i];
      if(s[idx] >= cLast) {
        res[idx] = 'C';
        cLast = e[idx];
      } else if(s[idx] >= jLast) {
        res[idx] = 'J';
        jLast = e[idx];
      } else {
        res = "IMPOSSIBLE";
        break;
      }
    }
    printf("Case #%d: %s\n", tc, res.c_str());
  }
  return 0;
}
