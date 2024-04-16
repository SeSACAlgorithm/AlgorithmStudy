answers = []

line = int(input())

for i in range(0, line):
    answers = input()
    answer = 0
    score = 0

    for j in answers:
        if j == 'O':
            score += 1
            answer += score
        else:
            score = 0

    print(answer)
