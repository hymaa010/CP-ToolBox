// Linear Sieve (Sieve of Eratosthenes in strict O(N) time and space).
// Stores the Least Prime Factor (lp[i]) and finds all primes up to N.
#include <bits\stdc++.h>
using namespace std;

const int N = 1e7;
vector<int> lp(N + 1);
vector<int> primes;
void sieve()
{
    for (int i = 2; i <= N; ++i) {
        if(lp[i] == 0) {
            lp[i] = i;
            primes.push_back(i);
        }
        for (int j = 0; i * primes[j] <= N; ++j) {
            lp[i * primes[j]] = primes[j];
            if (primes[j] == lp[i]) {
                break;
            }
        }
    }
}