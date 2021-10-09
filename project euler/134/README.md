# Project Euler #134
The problem statement is here: https://projecteuler.net/problem=134

Let f(x, y) equal the smallest number divisible by x with last digits formed by y. Let l(x) equal the smallest power of 10 greater than x. 
```
f(x, y) = n*l(y) + y == 0 (mod x)
n*l(y) == -y (mod x)
n == -y / l(y) (mod x)
```
Since all the computations of f(x, y) are on prime numbers, we are guaranteed to have a modular inverse for l(y). I calculate l(x) using `l(x)=exp10(floor(log10(x))+1)`, and then take its inverse using the extended euclidean algorithm. Now that we know `n` we can simply sum `n*l(y)+y` over all consecutive prime values of x and y (primes are found using the Sieve of Erastosthenes). 