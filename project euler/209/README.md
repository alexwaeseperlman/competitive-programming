# Project Euler #209

Problem statement here: https://projecteuler.net/problem=209

I found it helpful to think of this as a graph problem. The each value of `a,b,c,d,e,f` in the truth table corresponds to a vertex, and it has an edge going to `b,c,d,e,f,a^(b&c)`. The question becomes "how many ways are there to assign 1s and 0s to each value in this graph, such that there is no 1 connected to another 1".
My first thought was to test whether or not there are any vertices with more than one incoming edge. There are not. I show this by writing an expression, which given on the value of bits `a,b,c,d,e,f` returns the values of the bits in the incoming vertex.
Let `g,h,i,j,k,l` be the values for the incoming vertex. `h,i,j,k,l,g^(h&i)=a,b,c,d,e,f`. `g^(h&i)=f => g=f^(h&i) => g=f^(a&b)`
Now that we know this, we know that every vertex has a unique incoming and outgoing connection (also it is possible for a vertex to be connected to itself, for example `0,0,0,0,0,0`).
It follows that every vertex in the graph is a member of a cycle. I tested it and found a few cycles of varying lengths, this was one of them:
```
100100 001001 010010 100100
```
How many ways are there to assign values to a cycle of length n? Let's think of it as a string of bits. First, notice that the first and last bits need to be the same, this is because it they both refer to the value of the same vertex, this will be used later. Next, since the neighbors of each bit are its connections, we know that there cannot be any pair of connected 1s. We'll start developing a function for the number of binary strings without any connected 1s, and then deal with the first restriction.

Let `f(n)` equal the number of valid solutions ignoring the first restriction, `b(n)` be the number starting (and ending) with 1, and `c(n)` be the number starting with 0.
We can find the number of binary strings without connected 1s using the following recurrence `f(n) = f(n-1) + f(n-2), f(1) = 2, f(2) = 3`. Obviously for strings of length 1 there are two possible values, `0`, and `1`. For strings of length 2 there are `00`, `01`, and `10`. The recurrence comes from the fact that a valid string with length n must consist of a valid string with length n-2 with a `01` appended, or a valid string with length n-1 with a `0` appended. Using similar logic it's possible to show that `b(n) = b(n-1) + b(n-2)`, and `c(n) = c(n-1) + c(n-2)`. Now, lets define the function `a(n)` as the number of valid strings (including the first restriction). In order to make the first and last digits the same we add `01` to the end of every string that starts with `1`, and `0` to the end of every string that starts with zero. Therefore `a(n) = b(n-2) + c(n-1)`. By testing some values I found that this is the same as `a(n) = F(n-2) + F(n)`, where F is the Fibonacci sequence.

From here the solution is to just multiply the values of `a(n)` for each cycle in the graph.
