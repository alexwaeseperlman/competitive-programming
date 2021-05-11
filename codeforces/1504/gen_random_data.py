import random
import sys

print(sys.argv[1])

for i in range(int(sys.argv[1])):
	print(random.randint(0, 1000000), random.randint(0, 1000000))
