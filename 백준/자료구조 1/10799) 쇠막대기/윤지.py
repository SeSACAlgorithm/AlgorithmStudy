arr = input()

stk = []
ans = 0

for i in range(len(arr)):
    if arr[i] == '(':
        stk.append('(')
    else:
        # 레이저인 경우
        if arr[i-1] == '(':
            stk.pop()
            ans += len(stk)
        else:
            stk.pop()
            ans += 1

print(ans)
