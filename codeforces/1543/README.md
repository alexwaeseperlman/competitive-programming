# Codeforces contest #1543

I ran this as a virtual contest for practice. I ended up doing pretty well on it.

# Problem A
The problem statement is here: [https://codeforces.com/contest/1543/problem/A](https://codeforces.com/contest/1543/problem/A)
I started by finding the largest gcd that can be reached using a sequence of moves. If $a=b$ it is clearly infinity. It turns out that the maximum gcd when $a \neq b$ is the absolute value of the difference between $a$ and $b$. This is because if x is $\gcd(a, b)$, $x > \abs(a-b) \implies 1 > \abs(\frac{a}{x} - \frac{b}{x})$, but since $a \neq b$ (we covered that case earlier), $\abs(\frac{a}{x} - \frac{b}{x}) \neq 0$, meaning $x \leq \abs(a-b)$. Since the difference between $a$ and $b$ doesn't change between operations, we can just calculate the minimum number of operations before this difference is their gcd. This is congruent to $a \pmod{x}$, or congruent to $-a \pmod{x}$. It's easy to find the minimum value from there.

# Problem B
The problem statement is here: [https://codeforces.com/contest/1543/problem/B](https://codeforces.com/contest/1543/problem/B)

The inconvenience of a track is the sum of the differences between the number of cars in each pair of sections. Simply distribute the cars as evenly as possible by placing $c$ or $c+1$ cars in each section (c is the floor of the total number of cars divided by number of sections) and count the number of pairs between $c$ and $c+1$ sections.

# Problem C
The problem statement is here: [https://codeforces.com/contest/1543/problem/C](https://codeforces.com/contest/1543/problem/C)
This was an interesting problem. I had some trouble with it because I'm not used to using floating point numbers. The solution was the following recursive algorithm:

Let $f(c, m, p, w)$ equal the expected number of rounds before drawing $p$, given that $w$ rounds have passed. Our goal is to find $f(c, m, p, 0)$. We know that $f(0, 0, 1, w)=w$. This is the stop condition. For all other inputs the function is defined like this:
1. Let out = 0.0
2. If $c=0$ skip the next two steps
3. Distribute the probability from $c$ using the method described in the problem statement
4. Add $c f(c_{new}, m_{new}, p_{new}, w+1)$ to out
5. Repeat steps 2, 3, and 4 for $m$
6. Return out

I'm not entirely sure why this was rated 1900. It's likely that a lot of people had issues with floating point precision.

# Problem D2
The problem statement is here: [https://codeforces.com/contest/1543/problem/D](https://codeforces.com/contest/1543/problem/D)
I'm skipping the solution to D1 because D2 solves it. The goal here is to test each every possible value for the original password from 1 to $n$. In order to test a value $y$, we need a way to undo the effects of every previous guess. In other words we need a function $f(y, g)$, which says "if the original password was $y$, after making each guess from $g_{0}..g_{y-1}$, what would it be now". Also, I define $\ominus$ as the inverse of $\oplus$. This is calculated by subtracting instead of adding each digit

Here is an algorithm for that:
1. $k$ := $y$
2. For each $x$ in $g$, $k$ := $x\ominus k$
3. Return $k$

This solution would technically work, but it runs in O(n^2) time so it might be too slow. Luckily the algorithm for calculating $f(y, g)$ can be made more efficient. 

Here is a slight rearrangement that highlights where the optimization can be made (it only works for even values of $y$).
1. $k$ := $y$
2. Iterate over $g$ two numbers at a time, $a,b$: $k$ := $b\ominus (a\ominus k)=b\ominus a \oplus k$
3. Return $k$

This shows that for even $y$, $k=y \ominus (g_{0} - g_{1} + g_2 - ... - g_{y-1})$. We can calculate this by alternating adding and subtracting the guess each iteration. A similar equation can be found for odd values of $y$. Guesses can be made efficiently using both of these functions.
