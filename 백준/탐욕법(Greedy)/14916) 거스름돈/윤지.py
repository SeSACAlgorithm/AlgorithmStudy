n = int(input())

five_coins = n // 5
remains = 0
chk = False

for i in range(five_coins, -1, -1):
    remains = n - i * 5
    if remains % 2 == 0:
        print(i + (remains // 2))
        chk = True
        break

if not chk:
    print(-1)
