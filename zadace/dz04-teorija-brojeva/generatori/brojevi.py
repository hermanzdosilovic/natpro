import random
N = int(raw_input())
print N
for i in range(N):
    print random.randint(1, 1000000000),
print
print random.randint(1, N) 
