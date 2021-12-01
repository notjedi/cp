#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

int N, M, D, S, countDose = 0;
tuple<int, int, int> info[1000];
pair<int, int> infected[50];
bool isContaminated[50] = {}, personMarked[50] = {}, mat[50][50] = {};

void markContaminated(int person, int time) {
  for (int i = 0; i < D; i++) {
    auto temp = info[i];
    if (get<0>(temp) == person && get<2>(temp) < time)
      mat[get<0>(temp)][get<1>(temp)] = true;
  }
}

int main() {

  freopen("badmilk.in", "r", stdin);
  freopen("badmilk.out", "w", stdout);
  cin >> N >> M >> D >> S;

  for (int i = 0; i < D; i++) {
    cin >> get<0>(info[i]) >> get<1>(info[i]) >> get<2>(info[i]);
    get<0>(info[i])--;
    get<1>(info[i])--;
    get<2>(info[i])--;
  }
  for (int i = 0; i < S; i++) {
    cin >> infected[i].first >> infected[i].second;
    infected[i].first--;
    infected[i].second--;
    markContaminated(infected[i].first, infected[i].second);
  }

  for (int i = 0; i < M; i++) {
    bool contaminated = true;
    for (int j = 0; j < S; j++) {
      auto temp = infected[j];
      if (!mat[temp.first][i]) {
        contaminated = false;
        break;
      }
    }
    if (contaminated)
      isContaminated[i] = true;
  }

  for (int i = 0; i < D; i++) {
    auto temp = info[i];
    if (isContaminated[get<1>(temp)] && !personMarked[get<0>(temp)]) {
      personMarked[get<0>(temp)] = true;
      countDose++;
    }
  }

  cout << countDose << endl;
  return 0;
}
