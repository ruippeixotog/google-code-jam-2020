#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>

#define MAXN 50

using namespace std;

string p[MAXN];

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    int n; scanf("%d\n", &n);
    for(int i = 0; i < n; i++)
      cin >> p[i];

    string prefix, suffix, middle;
    bool fail = false;
    for(int i = 0; i < n; i++) {
      int pn = (int) p[i].size();

      int j0 = 0;
      for(; j0 < prefix.length(); j0++) {
        if(p[i][j0] == '*') break;
        if(p[i][j0] != prefix[j0]) { fail = true; break; }
      }
      if(fail) break;
      for(; p[i][j0] != '*'; j0++) {
        prefix.push_back(p[i][j0]);
      }

      int j1 = pn - 1;
      for(; pn - 1 - j1 < suffix.length(); j1--) {
        if(p[i][j1] == '*') break;
        if(p[i][j1] != suffix[pn - 1 - j1]) { fail = true; break; }
      }
      if(fail) break;
      for(; p[i][j1] != '*'; j1--) {
        suffix.push_back(p[i][j1]);
      }

      while(++j0 < j1) {
        if(p[i][j0] != '*') {
          middle.push_back(p[i][j0]);
        }
      }
    }
    reverse(suffix.begin(), suffix.end());
    prefix += middle + suffix;
    printf("Case #%d: %s\n", tc, fail ? "*" : prefix.c_str());
  }
  return 0;
}
