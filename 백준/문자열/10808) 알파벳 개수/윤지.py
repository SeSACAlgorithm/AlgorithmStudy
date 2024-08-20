S = input()

ans_arr = [0] * 26

for s in S:
    index = ord(s) - ord('a')
    ans_arr[index] += 1

print(" ".join(map(str, ans_arr)))
