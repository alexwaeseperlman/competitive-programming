# Codeforces contest #1515

## Problem E
I attempted this problem while upsolving after one of my first codeforces contests back in May 2021.
At the time I had no ideas on how to approach it.
8 months later, a few days ago, I had the idea to attempt this problem again. 
Now I have finally solved it.

I solved it using dynamic programming, defining the state as `dp[i][j] = (the number of ways to turn on the first i computers by booting exactly j computers manually)`.

The first question I needed to answer was how to calculate the most simple case: `dp[i][i]`. It turns out that this exactly $2^{i-1}$.

Proof:

> In order to turn on the first i computers manually, we need to ensure that none of them are turned on automatically. This means that there should never be more than one contiguous region of turned on computers in the range [1..i]. If there ever were, then a computer would be turned on automatically as they are connected. Therefore, after the first computer in region [1..i] is turned on, every subsequent computer that is turned on must be adjacent to a computer that is already on. Let x be the index of the first computer that Phoenix turns on in the region [1..i]. In the process of turning the rest of the computers on, he must turn on x-1 computers to the left of the first one, and i-x computers to the right of the first one. Both the regions [1..x] and [x..i] have at most one computer that can be turned on in any given step. This is because that computer must currently be off, and be adjacent to a computer that is currently on. This means that the only control Phoenix has over how to turn the computers on is whether to put one to the left or to the right of x at each step. In other words, the order of turning on all the computers in the region [1..i] can be uniquely represented as an initial position, x, and a string of x-1 'L's and i-x 'R's. So, given x, we can calculate the number of 'L/R' strings using (i-1) choose (x-1). We can sum from x=1 to x=i to find the total number of orderings, which clearly equals $2^{i-1}$. 

The next step is to find `dp[i][j]` for values of j other than i. This is also a little bit complicated. First notice that we can directly transition from `dp[i][j]` to `dp[i+x][j+x-1]` for all values of x by manually enabling all the computers in the region [i+2..i+x]. The (i+1)th computer will be turned on automatically. Also, the moves that are used to turn on the region [i+2..i+x] can be inserted anywhere, not necessarily contiguously, in between/before/after the moves that are used to turn on the region [1..i]. This means that while transitioning from `dp[i][j]` to `dp[i+x][j+x-1]` we need to multiply by (x+j) choose (x) to take into account those extra orderings. So to calculate our transitions at position i we can loop for each x in [1..n-x], and add `dp[i+x][j+x-1] += dp[i][j]*choose(x+j, x)`. We run that transition for each i in [1..n] in increasing order, and the final answer is the sum of all `dp[n][j]` for all j in [1..n].
