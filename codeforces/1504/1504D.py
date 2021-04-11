import sys
positions = (0, 0), (1, 0)

n = int(input())

colors = {'a': None, 'b': None}
pointers = {'a': 0, 'b': 1}

def step(pointer, n):
    if n % 2 == 1: return pointer + 2
    if (pointer + 1) % n == 0: return pointer + 1
    if (pointer + 2) % n == 0: return pointer + 3
    return pointer + 2

done_checker = False
secondary = None
primary = None

while True:
    blocked = int(input())

    if colors['a'] is None: colors['a'] = blocked % 3 + 1

    color = colors['a']
    pointer = 'a'

    if blocked == colors['a']:
        if colors['b'] is None: colors['b'] = blocked % 3 + 1
        color = colors['b']
        pointer = 'b'

    if done_checker:
        color = 6 - colors[primary] - blocked
        if colors[primary] == blocked: color = blocked % 3 + 1
        pointer = secondary

    print(color, pointers[pointer] // n + 1, pointers[pointer] % n + 1)
    sys.stdout.flush()

    pointers[pointer] = step(pointers[pointer], n)

    if pointers[pointer] >= n * n:
        if done_checker: break
        done_checker = True
        primary = pointer
        secondary = 'a' if pointer == 'b' else 'b'
