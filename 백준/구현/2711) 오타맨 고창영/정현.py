T = int(input())

for i in range(T):
    num, word = input().split()
    num = int(num)

    print(word[:num-1] + word[num:])