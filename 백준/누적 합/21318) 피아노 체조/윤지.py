import sys
input = sys.stdin.read
output = sys.stdout.write

data = input().split()

N = int(data[0])
piano = list(map(int, data[1:N+1]))
Q = int(data[N+1])
Q_arr = data[N+2:]

# 실수
fail = [0] * N
for i in range(N-1):
    if piano[i] > piano[i+1]:
        fail[i] = 1

tmp = [0] * N
tmp[0] = fail[0]
for i in range(1, N):
    tmp[i] = tmp[i - 1] + fail[i]

answer = []
for i in range(Q):
    x, y = map(int, Q_arr[i*2:i*2+2])
    x, y = x-1, y-1

    if x == y:
        answer.append(0)  # x == y인 경우 실수 없음
    elif x == 0:
        answer.append(tmp[y - 1])
    else:
        answer.append(tmp[y - 1] - tmp[x - 1])

output("\n".join(map(str, answer)) + "\n")


