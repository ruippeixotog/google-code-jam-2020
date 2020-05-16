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
#include <cmath>

#define MAXN 2000
#define INF 0x3f3f3f3f

using namespace std;

typedef long long ll;
typedef long double ld;

int x[MAXN], y[MAXN];

ll bf(ll& l, ll& r) {
  ll k = 1;
  while(l >= k || r >= k) {
    if(r > l) r -= k;
    else l -= k;
    k++;
  }
  return k - 1;
}

ll seriesSum(ll k, ll start, ll jump) {
  return k * (2 * start + (k - 1) * jump) / 2;
}

ll revSeriesSum(ll sum, ll start, ll jump) {
  ll lower = 0, upper = (ll) sqrt(sum) + 1;
  while(lower < upper) {
    ll mid = (lower + upper + 1) / 2;

    ll res = seriesSum(mid, start, jump);
    if(res < 0) {
      cerr << "ERROR!" << endl;
    }
    if(res > sum) upper = mid - 1;
    else lower = mid;
  }
  return lower;
}

//ll revSeriesSum2(ll sum, ll start) {
//  return (ll) ((sqrt(start * start - 2 * start + 4 * sum + 1) - start + 1) / 2);
//}

ll solve(ll& l, ll& r) {
//  cerr << "l = " << l << ", r = " << r << endl;

  ll diff = abs(l - r);
  ll k = (ll) ((sqrt(8 * (ld) diff + 1) - 1) / 2);
//  cerr << "diff = " << diff << ": " << k << endl;

  (r > l ? r : l) -= seriesSum(k, 1, 1);
  k++;
//  cerr << "l = " << l << ", r = " << r << endl;

  ll decL, decR;
  if(r > l) {
    decR = revSeriesSum(r, k, 2);
    decL = revSeriesSum(l, k + 1, 2);
    r -= seriesSum(decR, k, 2);
    l -= seriesSum(decL, k + 1, 2);
  } else {
    decL = revSeriesSum(l, k, 2);
    decR = revSeriesSum(r, k + 1, 2);
    l -= seriesSum(decL, k, 2);
    r -= seriesSum(decR, k + 1, 2);
  }
  return k + decL + decR - 1;
}

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    ll l, r; scanf("%lld %lld\n", &l, &r);

    ll n = solve(l, r);
    printf("Case #%d: %lld %lld %lld\n", tc, n, l, r);
  }
  return 0;
}
