#include <algorithm>
#include <cstdio>
#include <cmath>
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

ll a, b;

string ask(ll x, ll y) {
//  cerr << "Q: " << x << " " << y << endl;
  //printf("%lld %lld\n", x - 1000000000LL, y - 1000000000LL);
  printf("%lld %lld\n", x - 1000000000LL, y - 1000000000LL);
  fflush(stdout);
  string ans; cin >> ans;
  cerr << "A: " << ans << endl;
  if(ans == "WRONG") {
    exit(0);
  }
  return ans;
}

ll distSq(ll x0, ll y0, ll x1, ll y1) {
  return (x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 * y0);
}

void go() {
  ll margin = -(a - 1000000000LL);
  ll diagRadius = sqrt(2.0) / 2.0 * a;

  ll minDiag = 1000000000LL - margin;
  ll maxDiag = 1000000000LL + margin;

  while(minDiag + 1 < maxDiag) {
    ll mid = (minDiag + maxDiag) / 2;

    string ans = ask(mid - diagRadius, mid - diagRadius);
    if(ans == "CENTER") return;
    if(ans == "HIT") {
      maxDiag = mid;
    } else {
      minDiag = mid + 1;
    }
  }

  cerr << " bs finished " << minDiag << " " << maxDiag << endl;

  for(int i = -50; i <= 50; i++) {
    for(int j = -50; j <= 50; j++) {
      if(
        distSq(1000000000LL + i, 1000000000LL + j, maxDiag - diagRadius, maxDiag - diagRadius) >= diagRadius &&
        distSq(1000000000LL + i, 1000000000LL + j, minDiag - diagRadius, minDiag - diagRadius) <= diagRadius) {

        string ans = ask(1000000000LL + i, 1000000000LL + j);
        if(ans == "CENTER") return;
      }
    }
  }
  exit(0);
}

int main() {
  int t; scanf("%d %lld %lld", &t, &a, &b);
  for(int tc = 1; tc <= t; tc++) {
//    bool found = false;
//    for(int i = -5; i <= 5 && !found; i++) {
//      for(int j = -5; j <= 5 && !found; j++) {
//        if(ask(i, j) == "CENTER") {
//          found = true;
//        }
//      }
//    }
    go();
  }
  return 0;
}
