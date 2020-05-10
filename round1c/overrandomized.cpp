#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

string r[10000];

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    int u; scanf("%d\n", &u);
    for(string& ri : r) {
      scanf("%*lld"); cin >> ri;
    }

    map<char, int> hist[u];
    for(string& ri : r) {
      for(int i = 0; i < ri.size(); i++) {
        hist[i][ri[i]]++;
      }
    }

    string res(10, ' ');
    vector<char> letters;
    for(auto& p : hist[1]) {
      letters.push_back(p.first);
    }
    sort(letters.begin(), letters.end(), [&hist](char c1, char c2) {
      return hist[0][c1] > hist[0][c2];
    });

    res[0] = *letters.rbegin();
    for(int i = 0; i < letters.size() - 1; i++) {
      res[i + 1] = letters[i];
    }
    printf("Case #%d: %s\n", tc, res.c_str());
  }
  return 0;
}
