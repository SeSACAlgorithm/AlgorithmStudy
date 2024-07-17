N = int(input())

ans = 0

for _ in range(N):
    word = input()

    tmp = set()
    last_char = ''
    chk = True

    for i in word:
        if i != last_char:
            if i in tmp:
                chk = False
            tmp.add(i)

            last_char = i

    if chk:
        ans += 1

print(ans)

