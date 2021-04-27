i=input
S,T,o,r,l=i(),i(),ord,range,len
n,A,B,h=[0]*4
a,u,s=o('a'),l(T)-1,l(S)
for i in r(u+1):h=h*26+o(T[i])-a
for i in r(s):
	n=n*26+o(S[i])-a;k=i-u+1
	if i>=u:
		if n==h:A+=k;B^=k
		n-=26**u*(o(S[i-u])-a)
print(f"{A}\n{B}")
