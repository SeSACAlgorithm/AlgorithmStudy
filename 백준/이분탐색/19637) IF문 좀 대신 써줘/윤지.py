import sys
from bisect import bisect_left

input = sys.stdin.read
data = input().splitlines()

N, M = map(int, data[0].split())

names = []
limits = []

for i in range(1,N+1):
    a, b = data[i].split()
    names.append(a)
    limits.append(int(b))

answer = []
for i in range(N+1, N+M+1):
    power = int(data[i])
    idx = bisect_left(limits, power)
    answer.append(names[idx])

sys.stdout.write("\n".join(answer) + "\n")
