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

#define MAXN 7
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;

typedef long long ll;
typedef long double ld;

ll n, x[MAXN], y[MAXN];

bool enter[MAXN], leave[MAXN];
int link[MAXN];
int best = 0;

void recordBest() {
  int cnt = 0;
  for(int i = 0; i < n; i++) {
    cnt += enter[i] || leave[i];
  }
  //  if(curr > best) {
  //    cerr << "newbest " << k << " " << dirX << " " << dirY << " " << curr << endl;
  //  }
  best = max(best, cnt);
}

void go(int k, ll dirX, ll dirY);

void chooseLink(int k, ll dirX, ll dirY) {
//  cerr << "chooseLink " << k << " " << dirX << " " << dirY << " " << curr << endl;

  if(enter[k]) {
    recordBest();
    return;
  }
  enter[k] = true;

  if(link[k] != -1) {
    go(link[k], dirX, dirY);

  } else {
    for (int i = 0; i < n; i++) {
      if (i == k) continue;

      if (link[i] == -1) {
        link[i] = k;
        link[k] = i;
        go(i, dirX, dirY);
        link[i] = link[k] = -1;
      }
    }
  }
  recordBest();
  enter[k] = false;
}

void go(int k, ll dirX, ll dirY) {
  if(leave[k]) {
    recordBest();
    return;
  }
  leave[k] = true;

  for(int i = 0; i < n; i++) {
    if(i == k) continue;

    if(dirX == INF) {
      chooseLink(i, x[i] - x[k], y[i] - y[k]);
    } else {
      if(
        ((x[i] - x[k]) > 0) == (dirX > 0) &&
        ((y[i] - y[k]) > 0) == (dirY > 0) &&
          (x[i] - x[k]) * dirY == (y[i] - y[k]) * dirX) {
//        fprintf(stderr, "using %lld %lld, can go from (%lld, %lld) to (%lld, %lld)\n", dirX, dirY, x[i], y[i], x[k], y[k]);
        chooseLink(i, dirX, dirY);
      }
    }
  }
  recordBest();
  leave[k] = false;
}

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    scanf("%lld\n", &n);
    for(int i = 0; i < n; i++)
      scanf("%lld %lld\n", &x[i], &y[i]);

    best = 0;
    for(int i = 0; i < n; i++) {
      memset(link, -1, sizeof(link));
      chooseLink(i, INF, INF);
    }
    printf("Case #%d: %d\n", tc, best);
  }
  return 0;
}
