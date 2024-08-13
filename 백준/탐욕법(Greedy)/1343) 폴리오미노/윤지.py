board = list(input())

A = 'AAAA'
B = 'BB'

tmp = 0
ans = []

for i in board:
    if i == 'X':
        tmp += 1
    elif i == '.' :
        if tmp % 2 != 0:
            print(-1)
            exit()
        while tmp >= 4:
            ans.append(A)
            tmp -= 4

        if tmp == 2:
            ans.append(B)
        ans.append('.')
        tmp = 0
    else:
        ans.append(i)

if tmp % 2 != 0:
    print(-1)
    exit()
else:
    while tmp >= 4:
        ans.append(A)
        tmp -= 4
    if tmp == 2:
        ans.append(B)

for i in ans:
    print(i, end = '')
