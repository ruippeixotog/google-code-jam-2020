#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    string s; cin >> s;

    string s2;
    int depth = 0;
    for(char ch : s) {
      int digit = ch - '0';
      for(; depth < digit; depth++) {
        s2.push_back('(');
      }
      for(; depth > digit; depth--) {
        s2.push_back(')');
      }
      s2.push_back(ch);
    }
    while(depth--) {
      s2.push_back(')');
    }
    printf("Case #%d: %s\n", tc, s2.c_str());
  }
  return 0;
}
