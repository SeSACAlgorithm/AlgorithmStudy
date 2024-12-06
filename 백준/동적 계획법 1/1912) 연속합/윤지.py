n = int(input())
numbers = list(map(int, input().split()))

cur_sum = numbers[0]
max_sum = numbers[0]

for i in range(1, n):
    cur_sum = max(numbers[i], cur_sum + numbers[i])
    max_sum = max(max_sum, cur_sum)

print(max_sum)
