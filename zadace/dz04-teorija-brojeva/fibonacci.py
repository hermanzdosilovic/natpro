def multiply(a, b):
  sol = [[0 for x in range(len(b[0]))] for x in range(len(a))]
  for i in range(len(a)):
    for j in range(len(b[0])):
      for k in range(len(a[0])):
        sol[i][j] += (a[i][k]%MOD)*(b[k][j]%MOD)
        sol[i][j] %= MOD
  return sol

MOD = 10**100
m = [[0, 1, 0], [1, 1, 0], [1, 1, 1]]
k = [[1, 0, 0], [0, 1, 0], [0, 0, 1]]
N = int(raw_input())
while N:
  if N%2:
    k = multiply(k, m)
  N /= 2
  m = multiply(m, m)
sol = multiply(k, [[1], [0], [0]])
print sol[2][0]
