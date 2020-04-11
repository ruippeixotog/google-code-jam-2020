#include <cstdio>
#include <utility>
#include <vector>

#define MAXR 31

using namespace std;

int row[MAXR];

int numZeroBits(int n) {
  int cnt = 0;
  while(n > 0) {
    cnt += n % 2 == 0;
    n /= 2;
  }
  return cnt;
}

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    int n; scanf("%d\n", &n);

    int mask = n;
    int zeroBits = 0;
    while(numZeroBits(mask) > zeroBits) {
      int newZeroBits = numZeroBits(mask);
      mask -= newZeroBits - zeroBits;
      zeroBits = newZeroBits;
    }

    row[0] = 1;
    int r = 0, k = 0;
    vector<pair<int, int>> sol = {};

    while((mask >> r) > 0) {
      bool fillRow = mask & (1 << r);

      sol.emplace_back(r, k);
      if(fillRow) {
        if(k == 0) {
          while(k < r) {
            sol.emplace_back(r, ++k);
          }
        } else {
          while(k > 0) {
            sol.emplace_back(r, --k);
          }
        }
        n -= 1 << r;
      } else {
        n--;
      }

      r++;
      if(k != 0) k++;
      for(int i = r; i >= 0; i--) {
        row[i] = (i == 0 ? 0 : row[i - 1]) + (i == r ? 0 : row[i]);
      }
    }

    while(n > 0) {
      sol.emplace_back(r, k);
      n--;
      r++;
      if(k != 0) k++;
    }

    printf("Case #%d:\n", tc);
    for(auto p : sol) {
      printf("%d %d\n", p.first + 1, p.second + 1);
    }
  }
  return 0;
}
