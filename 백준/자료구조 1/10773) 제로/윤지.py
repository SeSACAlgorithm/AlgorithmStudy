for i in range(0, K):
    tmp = int(input())

    if tmp == 0:
        numbers.pop()
    else:
        numbers.append(tmp)

print(sum(numbers))
