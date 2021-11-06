# Codeforces contest #1594

# Problem A
Problem statement: [https://codeforces.com/contest/1594/problem/A](https://codeforces.com/contest/1594/problem/A)

If l=-n and r=n, all of the values cancel out to make zero. Set l=-n+1 and r=n, that way all of the values between -n+1 and n-1 cancel out, and the only remaining value is n.

# Problem B
Problem statement: [https://codeforces.com/contest/1594/problem/B](https://codeforces.com/contest/1594/problem/B)

The kth special number looks the same as n in base 2, except it should be interpreted as base n number. Just do a standard base conversion.

# Problem C
Problem statement: [https://codeforces.com/contest/1594/problem/B](https://codeforces.com/contest/1594/problem/B)

I first noticed that you can set the whole string, no matter its contents, in two operations, x = {n, n-1}. Also, clearly, if all of the characters in the string are equal to c then no operations are necessary. The question now becomes, when is only 1 operation necessary. If only one operation is necessary, and x is such that there is more than one multiple of x less than n, then there will also be a one operation solution using every multiple of x under n. This means that we can only test values of x greater than n/2. Also, since each of these values has only one multiple under n, we only need to test one location to see if it is a valid solution. Iterate from i=n/2 to i=n, and if s[i] = c there is a one operation solution with x={i}.

I actually took a while to get this because I was indexing from zero instead of from 1. I need to pay closer attention to that in the future.

# Problem D
Problem statement: [https://codeforces.com/contest/1594/problem/D](https://codeforces.com/contest/1594/problem/D)

It's possible to use a breadth-first-search to check which individuals are crewmates and which are imposters. Start by assuming that player 1 is a crewmate, this isn't necessarily true, but I will resolve it later. Every time a player is visited, append all of his comments to the search, adjusted for whether or not he is lying. When visiting a player that has been visited before, compare his role according to the comment that brought us to him, with the one that was previously set. If these are different then there is a contradiction, so return -1. 

Another important fact is that comments actually go both ways; if a says b is a crewmate then b is a crewmate if and only if a is a crewmate, since this operation is commutative we can add a new comment saying that b says a is a crewmate. This makes the bfs simpler because you can traverse a group of connected players using just one starting point.

If the optimal solution has player 1 as an imposter, we can simply flip the roles of every player. To see whether or not player 1 should be an imposter or a crewmate we can simply compare the two counts.

# Problem E1
Problem statement: [https://codeforces.com/contest/1594/problem/E1](https://codeforces.com/contest/1594/problem/E1)

The root note is allowed to choose from 6 colours. Every child node is allowed to choose from 4 (6 minus the two removed ffrom its parent). This is equivalent to ((4^(2^k-2))*6)%1000000007.

# Problem E2
Problem statement: [https://codeforces.com/contest/1594/problem/E2](https://codeforces.com/contest/1594/problem/E2)

I don't have a working solution to this problem, but I had some ideas. I'm putting them here in case I come back to try and solve it another time.

First, similarly to E1, most nodes have exactly 4 possible colours. The only ones that don't are the first, and those directly connected to nodes who's colours are already fixed. I think it's possible to solve this problem by storing the number of colours for all the nodes that we know don't have 4, and multiplying their value instead of 4 in the total.
