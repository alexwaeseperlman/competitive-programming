# Project Euler #216

Problem statement here: https://projecteuler.net/problem=216

This problem is technically possible to bruteforce, but I decided to find an efficient solution anyways. I decided to start by finding which prime numbers are 'relevant' (some prime numbers are not factors of `2*n^2-1` for any n). The math for that wasn't too complicated:
```
   p|2n^2-1
=> 2n^2-1 == 0 (mod p)
=> n^2 == 1/2 (mod p)
```
The modular inverse of 2 is `(p+1)/2` for any prime number. This means that `p` is only 'relevant' if `(p+1)/2` is a quadratic residue mod p. Once I realized this I tested how common these 'relevant' primes are, the idea being that if they aren't very common then I use them to do a more efficient bruteforce. About 50% of primes qualify, which means that there must be a more efficient method. Going back to the formula above I saw that:
```
   n^2 == 1/2 (mod p)
=>   n == (+ or -) sqrt(1/2) (mod p)
```
The square root of `1/2` can be calculated using either Tonelli-Shanks or Cipolla's algorithm. I found it easier to understand Cipolla's so I went with that. I used the Sieve of Erastosthenes to find all the primes under 75,000,000 (primes above 50,000,000 need to be included because they can still have values of `n` that are less than 50,000,000). Then I sieved out every value that is congruent to an `n` from a prime, except for those where `2*n^2-1 = p`. Then, after counting the numbers left after the sieve, I had the answer.

