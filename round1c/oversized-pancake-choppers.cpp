#include <algorithm>
#include <cstdio>
#include <map>
#include <set>
#include <vector>

#define MAXN 10000

using namespace std;

typedef long long ll;

ll a[MAXN];

ll gcd(ll k1, ll k2) {
  return k2 == 0 ? k1 : gcd(k2, k1 % k2);
}

struct Frac {
  ll num, denom;
  Frac(ll nm, ll dm): num(nm / gcd(nm, dm)), denom(dm / gcd(nm, dm)) {}

  bool operator<(const Frac& o) const {
    return num * o.denom < o.num * denom;
  }
};

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    int n, d; scanf("%d %d\n", &n, &d);
    for(int i = 0; i < n; i++)
      scanf("%lld", &a[i]);

    map<Frac, multiset<ll>> sliceSizes;
    for(int i = 0; i < n; i++) {
      for(int j = 1; j <= d; j++) {
        sliceSizes[{a[i], j}].insert(j);
      }
    }

    vector<Frac> sliceSizeVec;
    for(auto& e : sliceSizes) {
      sliceSizeVec.push_back(e.first);
    }
    int lower = 0, upper = (int) sliceSizeVec.size() - 1;
    while(lower < upper) {
      int mid = (upper + lower + 1) / 2;
      Frac& sliceSize = sliceSizeVec[mid];

      ll slices = 0;
      for(int i = 0; i < n && slices < d; i++) {
        slices += a[i] * sliceSize.denom / sliceSize.num;
      }

      if(slices >= d) lower = mid;
      else upper = mid - 1;
    }
    Frac maxSliceSize = sliceSizeVec[lower];

    int minCuts = d;
    for(auto& e : sliceSizes) {
      if(maxSliceSize < e.first) break;
      int slicesLeft = d, cuts = 0;
      for(ll slices : e.second) {
        if(slices > slicesLeft) break;
        cuts += slices - 1;
        slicesLeft -= slices;
      }
      minCuts = min(minCuts, cuts + slicesLeft);
    }

    printf("Case #%d: %d\n", tc, minCuts);
  }
  return 0;
}
