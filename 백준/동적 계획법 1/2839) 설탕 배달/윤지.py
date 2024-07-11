N = int(input())

bags_5 = N //5

ans = 0

while bags_5 >= 0:
    remains = N - bags_5 * 5
    if remains % 3 == 0:
        bags_3 = remains // 3
        ans = bags_3 + bags_5
        break
    bags_5 -= 1
else:
    ans -= 1

print(ans)

