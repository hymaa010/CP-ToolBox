#include <bits\stdc++.h>
using namespace std;

// Returns all divisors of n in O(sqrt(n)) time.
vector<int> getDivisors(int n){
    vector<int> divs;
    for(int d = 1; d * d <= n; ++d){
        if(n % d == 0) {
            divs.push_back(d);
            if(d != n / d) divs.push_back(n / d);
        }
    }
    return divs;
}
