N = int(input())

arr = []
dict = {}

for i in range(N):
    arr.append(input())

    # 확장자만 짜름
    tmp = arr[i].split('.')[-1]

    if tmp in dict:
        dict[tmp] += 1
    else:
        dict[tmp] = 1

# 정렬
for d in sorted(dict):
    print(f"{d} {dict[d]}")

