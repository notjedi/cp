#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool cmpPair(pair<ll, ll> a, pair<ll, ll> b) { return a.second < b.second; }

int main() {

  int numMovies, count = 0;
  cin >> numMovies;
  pair<ll, ll> showTimes[numMovies];
  for (int i = 0; i < numMovies; i++)
    cin >> showTimes[i].first >> showTimes[i].second;

  sort(showTimes, showTimes + numMovies, cmpPair);
  ll lastEndTime = -1;

  for (int i = 0; i < numMovies; i++) {
    if (showTimes[i].first >= lastEndTime) {
      lastEndTime = showTimes[i].second;
      count++;
    }
  }

  cout << count;
}
