#include <bits/stdc++.h>

using namespace std;
using ll = long long;
map<string, vector<string>> info;
map<string, int> charCount;
int maxYes = 0;

int main() {

  freopen("guess.in", "r", stdin);
  freopen("guess.out", "w", stdout);
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    string name, temp;
    int k;
    cin >> name >> k;
    for (int j = 0; j < k; j++) {
      cin >> temp;
      info[name].push_back(temp);
      charCount[temp]++;
    }
  }

  for (auto temp : info) {
    int tempCount = 0, done = 0;
    for (auto chars : temp.second) {
      if (charCount[chars] == 1 && !done) {
        tempCount++;
        done = 1;
        continue;
      }
      if (charCount[chars] > 1)
        tempCount++;
    }
    maxYes = max(maxYes, tempCount);
  }

  cout << maxYes;
  return 0;
}
