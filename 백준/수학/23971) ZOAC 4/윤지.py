H, W, N, M = map(int, input().split())

x = (W + M) // (M+1)
y = (H + N) // (N+1)

print(int(x * y))
