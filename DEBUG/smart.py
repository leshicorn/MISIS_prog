A, K, B, M, X = map(int, input().split())
L, R = 0, X * max(A, B)

while R - L > 1:
  min = (L + R) // 2
  if (min - min // K) * A + (min - min // M) * B >= X:
    R = min
  else:
    L = min

print(R)