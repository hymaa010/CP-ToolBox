// Standard Modular Arithmetic Operations (Addition, Subtraction, Multiplication)

int add(int a, int b, int M){
    return ((a % M) + (b % M)) % M;
}
 
int subtract(int a, int b, int M){
    return ((a % M) - (b % M) + M) % M;
}
 
int mul(int a, int b, int M){
    return (a % M) * (b % M) % M;
}
