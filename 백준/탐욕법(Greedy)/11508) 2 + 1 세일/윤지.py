N = int(input())
prices = [int(input()) for _ in range(N)]

prices.sort(reverse=True)

tot_price = 0

for i in range(N):
        if i % 3 != 2:
            tot_price += prices[i]

print(tot_price)
