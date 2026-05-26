// Counts the number of divisors of n in O(sqrt(n)) time.
int cntDivisors(int n){
    int cnt = 0;
    for(int d = 1; d * d <= n; ++d){
        if(n % d == 0) {
            cnt++;
            if(d != n / d) cnt++;
        }
    }
    return cnt;
}
