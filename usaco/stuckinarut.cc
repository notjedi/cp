#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
using ll = long long;

ll MAX_NUM = numeric_limits<ll>::max();
tuple<ll, ll, int> northPts[50];
tuple<ll, ll, int> eastPts[50];
ll squares[50];
bool moving[50];

bool cmpNorth(tuple<ll, ll, int> a, tuple<ll, ll, int> b) {
  return get<0>(a) < get<0>(b);
}

bool cmpEast(tuple<ll, ll, int> a, tuple<ll, ll, int> b) {
  return get<1>(a) < get<1>(b);
}

int main() {

  int n, north = 0, east = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    char direction;
    ll x, y;
    cin >> direction >> x >> y;
    if (direction == 'N')
      northPts[north++] = make_tuple(x, y, i);
    else
      eastPts[east++] = make_tuple(x, y, i);
  }

  fill_n(moving, n, true);
  fill_n(squares, n, 0);
  sort(northPts, northPts + north, cmpNorth);
  sort(eastPts, eastPts + east, cmpEast);

  for (int i = 0; i < north; i++) {
    for (int j = 0; j < east; j++) {

      auto a = make_pair(get<0>(northPts[i]), get<1>(northPts[i]));
      auto b = make_pair(get<0>(eastPts[j]), get<1>(eastPts[j]));
      if (!(a.first > b.first && a.second < b.second))
        continue;
      if (!moving[get<2>(northPts[i])] || !moving[get<2>(eastPts[j])])
        continue;

      int vertDist = b.second - a.second, horDist = a.first - b.first;
      // north (a) will stop
      if (vertDist > horDist) {
        int idx = get<2>(northPts[i]);
        moving[idx] = false;
        squares[idx] = vertDist;
      }
      // east (b) will stop
      if (vertDist < horDist) {
        int idx = get<2>(eastPts[j]);
        moving[idx] = false;
        squares[idx] = horDist;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    if (squares[i] == 0)
      cout << "Infinity" << endl;
    else
      cout << squares[i] << endl;
  }
  return 0;
}
