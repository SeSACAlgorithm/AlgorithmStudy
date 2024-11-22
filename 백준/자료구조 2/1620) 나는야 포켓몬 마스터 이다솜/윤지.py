import sys
input = sys.stdin.read

data = input().splitlines()

N, M = map(int, data[0].split())

monsters_index = {}
monsters_name = {}
answer = []

for i in range(1, N+1):
    name = data[i]
    monsters_index[i] = name
    monsters_name[name] = i

for j in range(N + 1, N + M + 1):
    quest = data[j]

    if quest.isdigit():
        answer.append(monsters_index[int(quest)])
    else:
        answer.append(str(monsters_name[quest]))

sys.stdout.write("\n".join(answer) + "\n")
