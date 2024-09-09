N = int(input())

ans = 1
if N != 0:
    for i in range(1, N+1):
       ans = ans * i

print(ans)
