def palindromize(s):
    yield s + ''.join((reversed(s)))
    yield s + ''.join(reversed(s))[1:]

def gen_palindromes(n):
    for i in range(n):
        yield from palindromize("{:b}".format(i))


n = 1000
print(n)
for i in gen_palindromes(n):
    print(len(i))
    print(i)

