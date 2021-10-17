#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
/* #define MAX 1e7; */
/* https://iq.opengenus.org/sieve-of-eratosthenes/ */

int main() {

  ll max = 1e6, ans = 0, var = 10001;
  vector<bool> arr(max, true);

  for (ll prime = 2; prime < max; prime++) {

    if (arr[prime]) {

      ans++;
      if (ans == var) {
        cout << prime << endl;
        break;
      }

      for (ll i = prime * prime; i < max; i += prime)
        arr[i] = false;
    }
  }
}
