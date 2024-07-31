T = int(input())

for i in range(T):
    enc_str = input()

    cnt = 0
    chk = {}

    for char in enc_str:
        if char.isalpha():
            if char in chk:
                chk[char] += 1
            else:
                chk[char] = 1

    max_cnt = max(chk.values(), default=0)

    most_frequent_chars = [char for char, cnt in chk.items() if cnt == max_cnt]
  
    if len(most_frequent_chars) > 1:
        print('?')
    else:
        print(most_frequent_chars[0])
