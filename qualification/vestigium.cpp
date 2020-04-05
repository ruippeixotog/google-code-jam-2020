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

#define MAXN 100

using namespace std;

int m[MAXN][MAXN];

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    int n; scanf("%d\n", &n);

    set<int> rowSet[MAXN], colSet[MAXN];
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        scanf("%d", &m[i][j]);
        rowSet[i].insert(m[i][j]);
        colSet[j].insert(m[i][j]);
      }
    }
    int k = 0, r = 0, c = 0;
    for(int i = 0; i < n; i++) {
      k += m[i][i];
      r += rowSet[i].size() < n;
      c += colSet[i].size() < n;
    }
    printf("Case #%d: %d %d %d\n", tc, k, r, c);
  }
  return 0;
}
