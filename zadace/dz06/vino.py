from math import factorial

s = [int(x) for x in raw_input().split()]
n = s[0]; m = s[1]; k = s[2]

def f(x):
  return factorial(x)

def next_permutation(arr):
  i = len(arr) - 1
  while i > 0 and arr[i - 1] >= arr[i]:
    i -= 1
  if i <= 0:
    return False

  j = len(arr) - 1
  while arr[j] <= arr[i - 1]:
    j -= 1
  arr[i - 1], arr[j] = arr[j], arr[i - 1]

  arr[i : ] = arr[len(arr) - 1 : i - 1 : -1]
  return True

def cannotContinue(x):
  h = min(k + 1, n + m)
  for i in range(0, h):
    if x[i] != 1:
      return False
  return True

def notGood(x):
  budget = k
  for i in range(0, n + m):
    if budget == 0 and x[i] == 1:
      return True
    elif x[i] == 1:
      budget -= 1
    else:
      budget += 1
  return False

x = []
sol = 0

for i in range(0, n):
  x.append(0)
for i in range(0, m):
  x.append(1)

while True:
  if cannotContinue(x):
    break
  if notGood(x):
    next_permutation(x)
    continue
  sol += 1
  if next_permutation(x) == False:
    break

p = f(n + m)/(f(n)*f(m))
print "%.4f" % ((1./p)*sol)
