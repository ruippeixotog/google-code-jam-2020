#include <cstdio>
#include <cstdlib>

#define INF 0x3f3f3f3f

using namespace std;

typedef long long ll;

ll seriesSum(ll k, ll start, ll jump) {
  return k * start + (k * (k - 1) / 2 * jump);
}

ll seriesSumInv(ll sum, ll start, ll jump) {
  ll lower = 0, upper = 2 * INF;
  while(lower < upper) {
    ll mid = (lower + upper + 1) / 2;

    if(seriesSum(mid, start, jump) > sum) {
      upper = mid - 1;
    } else {
      lower = mid;
    }
  }
  return lower;
}

ll solve(ll& l, ll& r) {
  ll k = seriesSumInv(abs(l - r), 1, 1);
  (r > l ? r : l) -= seriesSum(k++, 1, 1);

  ll stl = r > l ? k + 1 : k;
  ll str = r > l ? k : k + 1;
  ll kl = seriesSumInv(l, stl, 2);
  ll kr = seriesSumInv(r, str, 2);
  l -= seriesSum(kl, stl, 2);
  r -= seriesSum(kr, str, 2);
  return k + kl + kr - 1;
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
