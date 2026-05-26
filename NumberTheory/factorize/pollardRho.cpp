// Pollard's Rho Integer Factorization Algorithm
// Time Complexity: O(N^(1/4)) - suitable for very large integers (up to 64-bit).
// Includes Miller-Rabin Primality Test for fast base-case detection.
#include <bits\stdc++.h>
using namespace std;
#define ll long long

// pollard rho factorization in N ^ 1/4:
typedef unsigned long long ull;
namespace PollardRho {
    mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
    const int N = 1e6 + 9;
    ll seq[N];

    ull modmul(ull a, ull b, ull M) {
        ll ret = a * b - M * (1.L / M * a * b);
        return ret + M * (ret < 0) - M * (ret >= (ll)M);
    }

    ull modadd(ull a, ull b, ull M) {
        ll ret = a + b;
        while (ret >= M) ret -= M;
        while (ret < M) ret += M;
        return ret;
    }

    ull modpow(ull b, ull e, ull mod) {
        ull ans = 1;
        for (; e; b = modmul(b, b, mod), e /= 2)
            if (e & 1) ans = modmul(ans, b, mod);
        return ans;
    }

    vector<int> lp(N + 1);
    vector<int> primes;
    void sieve()
    {
        for (int i = 2; i <= N; ++i) {
            if(lp[i] == 0) {
                lp[i] = i;
                primes.push_back(i);
            }
            for (int j = 0; i * primes[j] <= N; ++j) {
                lp[i * primes[j]] = primes[j];
                if (primes[j] == lp[i]) {
                    break;
                }
            }
        }
    }

    bool isPrime(ull n) {
        if (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;
        ull A[] = {2, 325, 9375, 28178, 450775, 9780504,
                   1795265022},
                s = __builtin_ctzll(n-1), d = n >> s;
        for (ull a : A) {
            ull p = modpow(a%n, d, n), i = s;
            while (p != 1 && p != n - 1 && a % n && i--)
                p = modmul(p, p, n);
            if (p != n-1 && i != s) return 0;
        }
        return 1;
    }

    // returns O(n^(1/4))
    ll pollard_rho(ll n) {
        while (1) {
            ll x = rnd() % n, y = x, c = rnd() % n, u = 1, v, t = 0;
            ll px = 0, py = 0;
            while (1) {
                seq[py++] = y = modadd(modmul(y, y, n), c, n);
                seq[py++] = y = modadd(modmul(y, y, n), c, n);
                if ((x = seq[px++]) == y) break;
                v = u;
                u = modmul(u, abs(y - x), n);
                if (!u) return __gcd(v, n);
                if (++t == 32) {
                    t = 0;
                    if ((u = __gcd(u, n)) > 1 && u < n) return u;
                }
            }
            if (t && (u = __gcd(u, n)) > 1 && u < n) return u;
        }
    }


    vector<ll> factorize(ll n) {
        if (n == 1) return vector <ll>();
        if (isPrime(n)) return vector<ll> {n};
        vector<ll> v, w;
        while (n > 1 && n < N) {
            v.push_back(lp[n]);
            n /= lp[n];
        }
        if (n >= N) {
            ll x = pollard_rho(n);
            v = factorize(x);
            w = factorize(n / x);
            v.insert(v.end(), w.begin(), w.end());
        }
        return v;
    }

}