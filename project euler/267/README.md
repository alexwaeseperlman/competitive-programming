# Project Euler #267
The problem statement is here: https://projecteuler.net/problem=267

The first thing I noticed is that, because multiplication is commutative, the order of wins/losses doesn't affect the outcome. The amount of money left after winning `w` rounds with a bet ratio of `x` is `f(x, w)=(1+2x)^w(1-x)^(1000-w)`. Let `m(w)` equal the maximum value of `f(x, w)`.

The next important piece of information is that `m(w)` is strictly increasing. Once a value of `w` is found where `m(w) >= 10^9`, the probability of winning that many times can be calculated using the binomial distribution (the probability of winning at least that many coin flips).

I used binary search to find `w` by searching for zero over `d/dx f(x, w) = 0`, because `d/dx f(x, w)` is strictly decreasing as x increases. Then I searched over `m(w)` to find the smallest value of w such that `m(w)` is greater than 10^9.

`minWins.cpp` finds the value of `w`, and probability.py calculates the probability from that value.