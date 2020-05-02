#include <algorithm>
#include <cstdio>
#include <utility>
#include <vector>

using namespace std;

vector<int> cards;
vector<pair<int, int>> sol;

void swap(int sz1, int sz2) {
  sol.emplace_back(sz1, sz2);
  vector<int> tmp(cards.size());
  copy(cards.begin(), cards.begin() + sz1, tmp.begin());
  copy(cards.begin() + sz1, cards.begin() + sz1 + sz2, cards.begin());
  copy(tmp.begin(), tmp.begin() + sz1, cards.begin() + sz2);
}

void solve(int r, int s) {
  while(!is_sorted(cards.begin(), cards.end())) {
    int sz1, sz2, gap;

    int r1 = cards[0];
    for(sz1 = 1; sz1 < r * s && cards[sz1] == r1; sz1++);

    int r2 = cards[sz1];
    for(sz2 = sz1 + 1; sz2 < r * s && cards[sz2] == r2; sz2++);

    for(gap = sz2 + 1; gap < r * s &&
      (cards[gap - 1] != r1 || cards[gap] != r2); gap++);

    if(gap == r * s) {
      swap(sz1, r * s - sz1);
    } else {
      swap(sz2, gap - sz2);
    }
  }
}

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    int r, s; scanf("%d %d\n", &r, &s);

    sol.clear();
    cards.clear();
    for(int i = 0; i < s; i++) {
      for(int j = 0; j < r; j++) {
        cards.push_back(j);
      }
    }

    solve(r, s);
    printf("Case #%d: %d\n", tc, (int) sol.size());
    for(auto p : sol) {
      printf("%d %d\n", p.first, p.second);
    }
  }
  return 0;
}
