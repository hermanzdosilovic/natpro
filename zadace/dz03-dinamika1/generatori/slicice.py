import random
a = [int(x) for x in raw_input().split(" ")]
M = a[0]; N = a[1];
print "%d %d %d" % (M, random.randint(1, 10), random.randint(1, 10))
for i in range(0, M):
  print random.randint(N/10, N)
