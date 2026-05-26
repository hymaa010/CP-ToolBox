#include <bits\stdc++.h>
using namespace std;

// Generates divisors for all numbers up to N (1e6) using a sieve-like approach in O(N log N) time.
const int N = 1e6 + 1;
vector<int> divs[N];
int cnt[N];

void gen(){
    for (int i = 1; i < N; ++i) {
        for (int j = i; j < N; j += i) {
            // i is a divisor of j
            divs[j].push_back(i);
            cnt[j]++;
        }
    }
}
