T = int(input())

for _ in range(T):
    N = int(input())
    prices = list(map(int, input().split()))

    max_price = 0
    answer = 0

    for price in reversed(prices):
        if price > max_price:
            max_price = price
        else:
            answer += max_price - price

    print(answer)
