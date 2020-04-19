#include <cstdio>
#include <cmath>
#include <functional>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

#define MAXN 1000000000
#define INF 0x3f3f3f3f

using namespace std;

typedef long long ll;

vector<pair<int, int>> initialCandidates = {
  {0, 0},
  {-MAXN / 2, -MAXN / 2}, {-MAXN / 2, MAXN / 2},
  {MAXN / 2, -MAXN / 2}, {MAXN / 2, MAXN / 2}
};

string ask(ll x, ll y) {
  printf("%lld %lld\n", x, y);
  fflush(stdout);
  string ans; cin >> ans;
  if(ans == "WRONG") {
    exit(0);
  }
  return ans;
}

ll findAxisCenter(ll initial, const function<string(ll)>& askFunc) {
  ll lowerMinX = -MAXN, upperMinX = initial;
  while(lowerMinX < upperMinX) {
    ll midMinX = floor((lowerMinX + upperMinX) / 2.0);
    string ans = askFunc(midMinX);

    if(ans == "CENTER") { return INF; }
    else if(ans == "HIT") { upperMinX = midMinX; }
    else { lowerMinX = midMinX + 1; }
  }
  ll lowerMaxX = initial, upperMaxX = MAXN;
  while(lowerMaxX < upperMaxX) {
    ll midMaxX = ceil((lowerMaxX + upperMaxX + 1) / 2.0);
    string ans = askFunc(midMaxX);

    if(ans == "CENTER") { return INF; }
    else if(ans == "HIT") { lowerMaxX = midMaxX; }
    else { upperMaxX = midMaxX - 1; }
  }
  return (lowerMinX + lowerMaxX) / 2;
}

void go() {
  pair<ll, ll> initialHit = {0, 0};
  for(auto c : initialCandidates) {
    string ans = ask(c.first, c.second);
    if(ans == "CENTER") return;
    if(ans == "HIT") { initialHit = c; break; }
  }

  ll x = findAxisCenter(initialHit.first, [&initialHit](ll guess) {
    return ask(guess, initialHit.second);
  });
  if(x == INF) return;
  ll y = findAxisCenter(initialHit.second, [&initialHit](ll guess) {
    return ask(initialHit.first, guess);
  });
  if(y == INF) return;

  ask(x, y);
}

int main() {
  int t; scanf("%d %*d %*d", &t);
  for(int tc = 1; tc <= t; tc++) {
    go();
  }
  return 0;
}
