import sys
input = sys.stdin.read

data = input().split()

N = int(data[0])
M = int(data[1])

S = set(data[2:N+2])

chk = data[N+2:N+2+M]
cnt = 0

for s in chk:
    if s in S:
        cnt += 1

print(cnt)
