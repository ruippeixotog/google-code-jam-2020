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

#define MAXN 2000
#define INF 0x3f3f3f3f

using namespace std;

typedef long long ll;
typedef long double ld;

vector<int> cards;

map<pair<int, int>, vector<pair<int, int>>> mem;
vector<pair<int, int>> sol;

bool isCorrect() {
//  cerr << "step";
//  for(int c : cards) {
//    cerr << " " << c;
//  }
//  cerr << endl;

  int last = -1;
  for(int c : cards) {
    if(c < last) {
//      cerr << "not found" << endl;
      return false;
    }
    last = c;
  }
//  cerr << "found" << endl;
  return true;
}

int go(int steps, int maxSteps) {
  if(isCorrect()) {
    return steps;
  }
  if(steps >= maxSteps) {
    return -1;
  }
  for(int i = 1; i < cards.size() - 1; i++) {
    for(int j = 1; j < cards.size() - i; j++) {
      vector<int> tmp(cards.size());
      copy(cards.begin(), cards.begin() + i, tmp.begin());
      copy(cards.begin() + i, cards.begin() + i + j, cards.begin());
      copy(tmp.begin(), tmp.begin() + i, cards.begin() + j);

      sol.emplace_back(i, j);
      int res = go(steps + 1, maxSteps);
      if(res != -1) {
        return res;
      }
      sol.pop_back();

      copy(cards.begin(), cards.begin() + j, cards.begin() + i);
      copy(tmp.begin(), tmp.begin() + i, cards.begin());
    }
  }
  return -1;
}

void init(int r, int s) {
  sol.clear();
  cards.clear();
  for(int i = 0; i < s; i++) {
    for(int j = 0; j < r; j++) {
      cards.push_back(j);
    }
  }
}

void preprocess() {
  for(int r = 2; r <= 5; r++) {
    for(int s = 2; s <= 7; s++) {
      if(r * s > 14) continue;

      cerr << "compute " << r << " " << s << endl;

      init(r, s);
//      cerr << "test";
//      for(int c : cards) {
//        cerr << " " << c;
//      }
//      cerr << endl;

      if(r == 2) {
        for(int i = 0; i < s - 1; i++) {
          sol.emplace_back(2 * (s - 1) - i, 1);
        }
      } else {
        int res = -1;
        for(int i = 1; i < 14; i++) {
          int res0 = go(0, i);
          if(res0 != -1) { res = res0; break; }
        }
      }
      mem[{r, s}] = sol;
    }
  }
}

int main() {
  preprocess();

  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    int r, s; scanf("%d %d\n", &r, &s);

    vector<pair<int, int>>& sol = mem[{r, s}];

    printf("Case #%d: %d\n", tc, (int) sol.size());
    for(auto p : sol) {
      printf("%d %d\n", p.first, p.second);
    }
  }
  return 0;
}
