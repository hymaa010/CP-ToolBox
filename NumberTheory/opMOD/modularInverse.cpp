// Note: This file contains duplicate definitions of extended_eculidean_algorithm and fastPower 
// to keep it completely self-contained for easy copy-pasting during contests.

#define ll long long

// ============================================================================
// METHOD 1: Modular Inverse using Extended Euclidean Algorithm
// Works for any 'a' and 'M' as long as gcd(a, M) == 1 (even if M is composite).
// Time Complexity: O(log(min(a, M)))
// ============================================================================

ll extended_eculidean_algorithm(ll a, ll b, ll & x, ll & y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
 
    ll x1, y1;
    ll d = extended_eculidean_algorithm(b,a%b,x1,y1);
    x = y1;
    y = x1 - y1 * (a/b);
    return d;
}
 
ll mod_inverse_ecludien(ll a, ll m){
    ll x, _;
    extended_eculidean_algorithm(a, m,x,_);
    return (x%m+m)%m;
}


// ============================================================================
// METHOD 2: Modular Inverse using Fermat's Little Theorem
// Works ONLY if M is a Prime number and gcd(a, M) == 1.
// Time Complexity: O(log M)
// ============================================================================

int fastPower(int a, int b, int M){
    a %= M;
    int ret = 1;
    while (b){
        if(b & 1) ret = ret * a % M;
        a = a * a % M;
        b >>= 1;
    }
    return ret;
}

int inverse(int x, int M){
    // M is prime
    // gcd(x, M) = 1
    return fastPower(x, M - 2, M);
}
