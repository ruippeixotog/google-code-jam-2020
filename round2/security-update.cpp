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
#include <numeric>

#define MAXN 100
#define MAXD 1000

using namespace std;

typedef long long ll;
typedef long double ld;

int x[MAXN];
int u[MAXD], v[MAXD];

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    int c, d; scanf("%d %d\n", &c, &d);
    x[0] = 0;
    for(int i = 1; i < c; i++) {
      scanf("%d", &x[i]);
      x[i] = -x[i];
    }
    vector<int> adjs[MAXN];
    for(int i = 0; i < d; i++) {
      scanf("%d %d", &u[i], &v[i]);
      u[i]--; v[i]--;
      adjs[u[i]].push_back(v[i]);
      adjs[v[i]].push_back(u[i]);
    }

    vector<int> ord(c);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [](int a, int b) {
      return x[a] < x[b];
    });

    map<pair<int, int>, int> latencies;
    for(int i = 0; i < c; i++) {
      int xi = ord[i];

      for(int adj : adjs[xi]) {
        if(x[adj] < x[xi]) {
          latencies[{xi, adj}] = latencies[{adj, xi}] = x[xi] - x[adj];
          break;
        }
      }
    }

    printf("Case #%d:", tc);
    for(int i = 0; i < d; i++) {
      printf(" %d",
        latencies.count({u[i], v[i]}) ? latencies[{u[i], v[i]}] : 1000000);
    }
    printf("\n");
  }
  return 0;
}
