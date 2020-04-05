#include <cstdio>
#include <iostream>
#include <set>
#include <string>
#include <vector>

#define MAXB 100

using namespace std;

int b;
bool arr[MAXB];

int ask(int p) {
//  cerr << "Ask " << (p + 1) << endl;
  printf("%d\n", p + 1);
  fflush(stdout);
  char ans[2]; scanf("%s", ans);
  if(ans[0] == 'N') {
    cerr << "Error" << endl;
    exit(0);
  }
  return ans[0] == '1';
}

void answer() {
  string res;
  for(int i = 0; i < b; i++) {
    res.push_back(arr[i] ? '1' : '0');
  }
  // cerr << "Answer " << res << endl;
  printf("%s\n", res.c_str());
  fflush(stdout);
  char ans[2]; scanf("%s", ans);
  if(ans[0] == 'N') {
    cerr << "Error" << endl;
    exit(0);
  }
}

void complement(int st, int end) {
  for(int i = st; i < end; i++) {
    arr[i] = !arr[i];
    arr[b - i - 1] = !arr[b - i - 1];
  }
}

void reverse(int st, int end) {
  for(int i = st; i < end; i++) {
    swap(arr[i], arr[b - i - 1]);
  }
}

void align(int st, int end) {
  int eq = -1, neq = -1;
  for(int i = st; i < end; i++) {
    if(arr[i] == arr[b - i - 1]) eq = i;
    else neq = i;
  }
  int eqRes = ask(eq >= 0 ? eq : 0);
  int neqRes = ask(neq >= 0 ? neq : 0);
  if(eq >= 0 && eqRes != arr[eq]) {
    complement(st, end);
  }
  if(neq >= 0 && neqRes != arr[neq]) {
    reverse(st, end);
  }
}

void fillPhase() {
  // cerr << "Fill phase" << endl;
  for(int i = 0; i < b / 2; i++) {
    arr[i] = ask(i);
    arr[b - i - 1] = ask(b - i - 1);
  }
}

void alignPhase() {
  int blockSize = 5;
  while(blockSize < b / 2) {
    // cerr << "Align phase, blockSize = " << blockSize << endl;
    for(int i = 0; i < b / 2; i += blockSize) {
      align(i, i + blockSize);
    }
    blockSize *= 5;
  }
}

int main() {
  int t; scanf("%d %d", &t, &b);
  for(int tc = 1; tc <= t; tc++) {
    fillPhase();
    alignPhase();
    answer();
  }
  return 0;
}
