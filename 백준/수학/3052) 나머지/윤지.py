lists = []

for i in range(0, 10):
    number = int(input()) % 42
    lists.append(number)

# 중복제거
tmp_set = set(lists)
lists = list(tmp_set)
result = len(lists)
print(result)