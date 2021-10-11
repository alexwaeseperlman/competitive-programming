# Project Euler #757

The problem statement is here: https://projecteuler.net/problem=757

We are given a system of two equations. I spent a while rearranging them without getting anywhere, so I wrote a script to bruteforce all of the solutions less than 100. After looking at these I noticed that the difference between c and a was always one more than the difference between d and b. This gave me the idea to rewrite the equation like this:
```
Let x equal a - c
  c = a-x
a+b = c+d+1
    = a-x+d+1
  b = -x+d+1
  d = b+x-1
 ab = (a-x)(b+x-1)
    = ab+ax-a-bx-x^2+x
  0 = -x^2-bx+ax+x-a
    = -x^2+(a-b+1)x-a
x^2 = (a-b+1)x-a
  x = (a-b+1)-a/x
```
Since x is an integer we know that a is a multiple of x.

Let k equal a/x
```
x^2 = (kx-b+1)x-kx
    = (kx-b+1-k)x
  x = kx-b+1-k
  b = kx-x-k+1
 ab = kx(kx-x-k+1)
  N = k^2x^2 - kx^2 - k^2x + kx
```

Now we just need to count the unique numbers of this form under 10^14. This is done by building an array and sorting it. Luckily these numbers grow very quickly which means there aren't that many to be counted. The overall complexity is O(sqrt(N) log(N)).