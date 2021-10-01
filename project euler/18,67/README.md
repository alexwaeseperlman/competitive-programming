# Project Euler #18 and #67

The problem statement for 18 is here: https://projecteuler.net/problem=18 They link to 67 on the page.

Both of these problems have the same solution so this analysis/explanation applies to both of them.

This was the kind of problem that screams for dynamic programming. Each triangle can be broken up into two subproblems, depending on whether the path turns left or right, and those subproblems can themselves be split. The reason why dynamic programming is so effective here is that the triangles created by the subproblems are heavily overlapping, meaning that most of the calculations can be shared between them. 

My solution was to build the paths up starting at the bottom. Let's look at the triangle from problem 18 for example. On the bottom left corner there is a 63 connected to 04 and 62. The optimal path clearly goes to the 62, meaning the optimal path for the subproblem starting at 63 has a score of 125. The neighboring subproblem is a 66 connected to the same 62 and a 98. The optimal path here clearly goes to the 98, which means it has a value of 160. We repeat this process for every subproblem in the row and then move one step up. The 91 on the bottom left is needs to choose between the 125 and the 160, and so on.
