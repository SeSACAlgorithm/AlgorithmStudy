N = int(input())

customers = []
tips = 0
orders = 1

for _ in range(N):
    customers.append(int(input()))

customers.sort(reverse=True)

for c in customers:
    tmp = c - (orders - 1)
    orders += 1
    if tmp < 0 :
        continue
    else:
        tips += tmp

print(tips)
