line = int(input())

for i in range(0, line):
    index, words = input().split()
    index = int(index)

    print(words[:index-1] + words[index:])
