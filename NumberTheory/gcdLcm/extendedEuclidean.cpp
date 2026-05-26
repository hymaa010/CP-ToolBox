// Extended Euclidean Algorithm
// Computes coefficients x and y such that a*x + b*y = gcd(a, b).
// Time Complexity: O(log(min(a, b)))
#define ll long long

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