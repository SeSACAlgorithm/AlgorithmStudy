line = int(input())
arr = set()

# 중복제거
for i in range(0, line):
    arr.add(input())

sorted_arr = sorted(arr, key=lambda x:(len(x), x))

for word in sorted_arr:
    print(word)
