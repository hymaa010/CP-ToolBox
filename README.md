# Competitive Programming Toolbox

Welcome to my personal, optimized repository of algorithms and templates for competitive programming. This repository is built for **speed, reliability, and correctness**. 

Every template is designed to be **completely self-contained**, allowing for instant copy-pasting directly into contest environments without worrying about missing headers or helper functions.

---

## 📂 Repository Structure

All Number Theory algorithms are organized cleanly by mathematical concepts:

```text
NumberTheory/
├── divsMultiples/             # Divisors and multiples calculations
│   ├── countDivisors.cpp      # O(sqrt(N)) divisor counter
│   ├── getDivisors.cpp        # O(sqrt(N)) divisor list generator
│   └── genMultiples.cpp       # O(N log N) sieve-like divisor precomputation
│
├── factorize/                 # Integer factorization algorithms
│   ├── primeFactorization.cpp # O(sqrt(N)) trial division factorization
│   └── pollardRho.cpp         # O(N^(1/4)) Pollard's Rho advanced factorization
│
├── gcdLcm/                    # GCD and Euclidean expansions
│   └── extendedEuclidean.cpp  # Extended Euclidean Algorithm
│
├── opMOD/                     # Modular Arithmetic & Modular Inverse operations
│   ├── modularArithmetic.cpp  # O(1) Modular Add, Subtract, Multiply
│   ├── fastPower.cpp          # O(log B) Binary Exponentiation
│   └── modularInverse.cpp     # O(log M) Modular Inverse (Self-Contained)
│
└── prime/                     # Primality tests and prime sieves
    ├── Sieve.cpp              # Standard and Least Prime Factor (LP) Sieves
    ├── linearSieve.cpp        # O(N) strict Linear Sieve
    ├── isPrime.cpp            # O(sqrt(N)) basic primality check
    └── millerRabin.cpp        # O(k log^3 N) deterministic Miller-Rabin test
```

---

## 📊 Complexity & Cheat Sheet Reference

Here is a quick reference of the available algorithms, their functions, and their complexity profiles:

| Sub-Module | File Name | Main Function(s) | Time Complexity | Space Complexity | Notes |
| :--- | :--- | :--- | :--- | :--- | :--- |
| **Divisors** | `countDivisors.cpp` | `cntDivisors(n)` | $O(\sqrt{N})$ | $O(1)$ | Counts number of divisors |
| | `getDivisors.cpp` | `getDivisors(n)` | $O(\sqrt{N})$ | $O(\sqrt{N})$ | Generates sorted list of divisors |
| | `genMultiples.cpp` | `gen()` | $O(N \log N)$ | $O(N \log N)$ | Precomputes all divisors up to $10^6$ |
| **Factorization** | `primeFactorization.cpp` | `primeFactorization(n)`<br>`primeFactorizationMap(n)` | $O(\sqrt{N})$ | $O(\log N)$ | Trial division factorization |
| | `pollardRho.cpp` | `PollardRho::factorize(n)` | $O(N^{1/4})$ | $O(\log N)$ | Extremely fast for 64-bit integers |
| **GCD / LCM** | `extendedEuclidean.cpp` | `extended_eculidean_algorithm` | $O(\log(\min(a, b)))$ | $O(\log(\min(a, b)))$ | Computes $ax + by = \gcd(a, b)$ |
| **Modular Ops** | `modularArithmetic.cpp` | `add(a, b, M)`, `subtract(...)`, `mul(...)` | $O(1)$ | $O(1)$ | Overflow-safe modular math |
| | `fastPower.cpp` | `fastPower(a, b, M)` | $O(\log B)$ | $O(1)$ | Modular binary exponentiation |
| | `modularInverse.cpp` | `mod_inverse_ecludien(a, M)`<br>`inverse(a, M)` | $O(\log M)$ | $O(1)$ | Fully self-contained copy-paste templates |
| **Primes** | `Sieve.cpp` | `sieve()` | $O(N \log \log N)$ | $O(N)$ | Option 1: Primality; Option 2: LP Sieve |
| | `linearSieve.cpp` | `sieve()` | $O(N)$ | $O(N)$ | Computes primes in linear time |
| | `isPrime.cpp` | `isPrime(n)` | $O(\sqrt{N})$ | $O(1)$ | Simple primality check |
| | `millerRabin.cpp` | `isPrime(n)` | $O(k \log^3 N)$ | $O(1)$ | Deterministic primality check for 64-bit |

---

## ⚡ Contest Guidelines

1. **Standalone Copy-Pasting:** 
   Every template file starts with standard C++ headers and is 100% self-contained. For example, `modularInverse.cpp` already contains copies of `fastPower` and the `extended_eculidean_algorithm` so you do not need to piece multiple files together.
2. **Double check constraints:**
   * For standard numbers $\le 10^9$, use standard trial division $O(\sqrt{N})$.
   * For numbers $\le 10^{18}$, make sure to use `millerRabin.cpp` and `pollardRho.cpp`.
   * For modular inverses, use `mod_inverse_ecludien` if the modulo is composite, and `inverse` (Fermat's) if the modulo is prime.
