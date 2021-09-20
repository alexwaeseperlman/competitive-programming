# Codeforces contest \#1574
I missed this contest because it happened during my morning class at school. I decided to solve some problems during computer science class in the afternoon.

## Problem A
The problem statement is here: https://codeforces.com/contest/1574/problem/A

The logic behind my solution is very simple. Start with a sequence of `n` open brackets and `n` closing brackets, then use the following pattern (using n=5 as an example):
```
((((()))))
(((()())))
((()()()))
(()(())())
()((()))()
```
Just move the center two brackets towards the outside one step at a time.

## Problem B
The problem statement is here: https://codeforces.com/contest/1574/problem/B

I liked this problem because it has a constant time solution. Here is the logic and proof:

Without loss of generality assume that a >= b >= c. The problem is symmetric in swapping any of their values. Knowing this, we can find a lower and upper bound for m. To find the upper bound just calculate a+b+c-2. This is achieved by placing all letters of the same type beside each other, like this:
```
a..ab...bc...c
```
There is no arrangement with more adjacent equal letters than this one because there are 3 different classes of letters, meaning there need to be unequal adjacent letters at least twice.

The lower bound is given by the formula a-b-c-1. Start by laying out all the `a`s like this:
```
a a ... a a
```
Now place the `b`s in the spaces starting at the left, and the `c`s in the spaces starting at the right. That looks like this:
```
abab..baac..caca
```
Each `b` can break up a pair of `a`s, and each `c` can break up a pair of `a`s. 1 is subtracted because we're counting pairs of letters ('aaaa' only has 3 pairs)

Since letters can be swapped around to fit any value of `m` within these bounds, the problem is as simple as checking if `m` is between them.

## Problem C
The problem statement is here: https://codeforces.com/contest/1574/problem/C

The solution to this turned out to be as simple as sorting the heroes' strength and checking a few numbers around the required strength to beat each dragon. The solution looks like this:
1. Check the first hero who has strength less than the defense score of this dragon. The gold cost is `max(0, defense - strength) + max(0, attack - defending heroes total strength)`. It's efficient to calculate the heroes' defense strength by subtracting the strength of the selected hero from the strength of all of them.
2. Compare that to the first hero who has strength greater than the defense score of the dragon. It's possible this will be cheaper.
One of those two will be optimal

## Problem D
The problem statement is here: https://codeforces.com/contest/1574/problem/D

I'm really happy with my solution to this because I finally got to use a trie. It ended up being O(min(m, 200000^n)), which got accepted, despite the fact that it's horribly inefficient. This was the strategy:
1. Select build that hasn't been tested yet with the highest score. This is done with a priority queue.
2. Check whether or not this build is banned (using a trie)
3. If it's not then we're done
4. If this build is banned then put every build that can be reached by subtracting 1 from one if its item slots into the queue. Use another trie of tested builds to avoid storing the same build twice
At the end of this process a solution is guaranteed


