N = int(input())
cards = set(map(int, input().split()))
M = int(input())
Q = list(map(int, input().split()))

answer = []

for q in Q:
    if q in cards:
        answer.append(1)
    else:
        answer.append(0)


print(" ".join(map(str, answer)))
