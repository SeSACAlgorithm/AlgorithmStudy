N = int(input())
cnt = 0

for _ in range(N):
    S = input()
    stk = []

    for s in S:
        if stk and stk[-1] == s:
            stk.pop()
        else:
            stk.append(s)

    if not stk:
        cnt += 1

print(cnt)
