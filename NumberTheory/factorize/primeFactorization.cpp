#include <bits\stdc++.h>
using namespace std;

// Prime Factorization using trial division in O(sqrt(n)) time.

// Returns a vector containing all prime factors (with duplicates)
vector<int> primeFactorization(int n){
 
    vector<int> ans;
    for (int i = 2; i * i <= n; ++i) {
        while (n % i == 0){
            ans.push_back(i);
            n /= i;
        }
    }
 
    if(n != 1) ans.push_back(n);
 
    return ans;
}
 
// Returns a map where keys are prime factors and values are their exponents
map<int, int> primeFactorizationMap(int n){
 
    map<int, int> ans;
    for (int i = 2; i * i <= n; ++i) {
        while (n % i == 0){
            ans[i]++;
            n /= i;
        }
    }
    if(n != 1) ans[n]++;
    return ans;
}
