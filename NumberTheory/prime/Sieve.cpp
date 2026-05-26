#include <bits\stdc++.h>
using namespace std;

// ============================================================================
// TEMPLATE OPTION 1: Standard Primality Sieve (isPr[i] = 1 if prime, else 0)
// Time Complexity: O(N log log N)
// ============================================================================

const int N = 1e7 + 1;
int isPr[N];
vector<int> primes;

void sieve(){
    for (int i = 2; i < N; ++i) isPr[i] = 1;
    for (int i = 2; i < N; ++i) {
        if(isPr[i]){
            primes.push_back(i);
            for (int j = i * i; j < N; j += i) {
                isPr[j] = 0;
            }
        }
    }
}

/* 
// ============================================================================
// TEMPLATE OPTION 2: Least Prime Factor Sieve (lp[i] stores smallest prime factor of i)
// Time Complexity: O(N log log N)
// ============================================================================

const int N = 1e7;
int lp[N];
vector<int> primes;

void sieve(){
    for (int i = 2; i < N; ++i) {
        if(!lp[i]){
            primes.push_back(i);
            for (int j = i * i; j < N; j += i) {
                if(!lp[j]) lp[j] = i;
            }
        }
    }
}
*/
