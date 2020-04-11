#include <algorithm>
#include <cstdio>
#include <map>
#include <queue>
#include <set>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    int r, c; scanf("%d %d\n", &r, &c);

    vector<map<int, int>> row(r), col(c);
    for(int i = 0; i < r; i++) {
      for(int j = 0; j < c; j++) {
        int sij; scanf("%d", &sij);
        row[i][j] = sij;
        col[j][i] = sij;
      }
    }

    ll roundInterest = 0;
    queue<pair<int, int>> toCheck;
    for(int i = 0; i < row.size(); i++) {
      for(auto p : row[i]) {
        toCheck.emplace(i, p.first);
        roundInterest += p.second;
      }
    }

    ll totalInterest = 0;
    while(true) {
      totalInterest += roundInterest;

      set<pair<int, int>> toCheckNext;
      vector<pair<int, int>> eliminated;

      while(!toCheck.empty()) {
        int i, j;
        tie(i, j) = toCheck.front(); toCheck.pop();

        auto rIt = row[i].find(j);
        int skill = rIt->second;

        vector<pair<int, int>> neighbors;

        int sumSkill = 0;
        if(rIt != row[i].begin()) {
          neighbors.emplace_back(i, prev(rIt)->first);
          sumSkill += prev(rIt)->second;
        }
        if(next(rIt) != row[i].end()) {
          neighbors.emplace_back(i, next(rIt)->first);
          sumSkill += next(rIt)->second;
        }
        auto cIt = col[j].find(i);
        if(cIt != col[j].begin()) {
          neighbors.emplace_back(prev(cIt)->first, j);
          sumSkill += prev(cIt)->second;
        }
        if(next(cIt) != col[j].end()) {
          neighbors.emplace_back(next(cIt)->first, j);
          sumSkill += next(cIt)->second;
        }

        if(!neighbors.empty() && skill * neighbors.size() < sumSkill) {
          eliminated.emplace_back(i, j);
          roundInterest -= skill;
          for(auto n : neighbors) {
            toCheckNext.insert(n);
          }
        }
      }

      if(eliminated.empty())
        break;

      for(auto p : eliminated) {
        row[p.first].erase(p.second);
        col[p.second].erase(p.first);
        toCheckNext.erase(p);
      }
      for(auto p : toCheckNext) {
        toCheck.push(p);
      }
    }

    printf("Case #%d: %lld\n", tc, totalInterest);
  }
  return 0;
}
