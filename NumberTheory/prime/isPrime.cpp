// Primality check using Trial Division in O(sqrt(n)) time.
int isPrime(int n){
    if(n == 1) return false;
    for(int d = 2; d * d <= n; ++d){
        if(n % d == 0) {
            return false;
        }
    }
    return true;
}