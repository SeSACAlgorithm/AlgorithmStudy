N = int(input())

if N < 10:
    N = N * 10

tmp = N
cnt = 0

while True:
    # 10의 자리
    a = tmp // 10

    # 1의 자리
    b = tmp % 10

    plus = a + b
    tmp = b * 10 + plus % 10
    cnt += 1

    if N == tmp:
        break


print(cnt)



