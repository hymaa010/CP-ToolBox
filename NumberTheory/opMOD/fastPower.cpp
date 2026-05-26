// Modular Exponentiation (Binary Exponentiation)
// Computes (a^b) % M in O(log b) time.
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