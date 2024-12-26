N, M = map(int, input().split())

non_hear = []
non_see = []

for _ in range(N):
    non_hear.append(input())

for _ in range(M):
    non_see.append(input())

answer = list(set(non_hear) & set(non_see))

answer.sort()
print(len(answer))
for a in answer:
    print(a)
