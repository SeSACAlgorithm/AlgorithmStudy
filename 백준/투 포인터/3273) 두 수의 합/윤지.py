n = int(input())
arr = list(map(int, input().split()))
x = int(input())

numbers = set()
ans = 0

for a in arr:
    tmp = x - a
    if tmp in numbers:
        ans += 1
    numbers.add(a)

print(ans)
