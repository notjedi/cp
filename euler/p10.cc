#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

/* https://cp-algorithms.com/algebra/sieve-of-eratosthenes.html */
int main() {

  ll limit = 2000000, sum = 0;
  vector<bool> isPrime(limit, true);

  for (ll prime = 2; prime < limit; prime++) {
    if (isPrime[prime]) {
      sum += prime;
      for (ll i = prime * prime; i < limit; i += prime)
        isPrime[i] = false;
    }
  }
  cout << sum << endl;
  return 0;
}
