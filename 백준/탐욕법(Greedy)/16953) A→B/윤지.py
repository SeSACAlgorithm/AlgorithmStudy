A, B  = map(int, input().split())

ans = 1

while A < B:
    if B % 10 == 1:
        B //= 10
    elif B % 2  == 0:
        B //= 2
    else:
        break
    ans += 1

if B == A:
    print(ans)
else:
    print(-1)
