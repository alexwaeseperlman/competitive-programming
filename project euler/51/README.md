# Project Euler #51

Problem statement here: https://projecteuler.net/problem=51

Brute force ended up being the easiest solution here. I generated a list of primes from 1 to 10 million, grouped them by digits, and then tried every possible mask and counted how many prime numbers are in that family. 

There are many optimizations that can be made, for example primes from a family that has already been tested don't need to be tested again, and certain masks can be skipped because they will never have a family of 8, but this solution ended up working fine. It runs in O(n^2/log(n)) time.
