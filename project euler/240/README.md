# Project Euler #240

The problem statement is here: https://projecteuler.net/problem=240

My first step in solving this was to write a `waysToSumTo` method. It returns a list of all of the unique ways to sum to `n` using `k` numbers between `low` and `high`. Calling this with `n=70,k=10,low=1,high=12` gives every possible combination of values for the top 10 dice. This was the algorithm I used:

1. Loop over each set of dice rolls that sum to 70
2. Count the number of unique orders that all the rolls, except for the smallest, in this set can happen in. Let's call this number `x`. Let's call the value of the smallest roll from the top ten `y`, and the number of times it was rolled in the top 10 `z`.
3. The smallest value needs to be treated separately because dice that weren't in the top 10 can be the same value as it, for example all 20 rolls can be 7.
4. For each value of `i` from 0 to 10, add `x * 10 choose (z+i) * (y-1) ^ (10 - z - i)` to the total. `i` represents the number of dice rolled with value `y` outside of the top 10. In this expression `10 choose (z+i)` represents the number of ways to place all the dice with value `y` in the remaining spaces (the first 10 spaces were taken by the top 10). `(y-1) ^ (10-z-i)` is the number of ways the remaining empty spaces can be filled.
