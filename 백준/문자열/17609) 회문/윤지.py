T = int(input())

for _ in range(T):
    s = input()

    front, end = 0, len(s) - 1

    is_pal = True

    # 회문
    while front < end:
        if s[front] == s[end]:
            front += 1
            end -= 1
        else:
            is_pal = False
            break

    # 유사회문
    if not is_pal:
        left_pal = True
        f, e = front + 1, end
        while f < e:
            if s[f] != s[e]:
                left_pal = False
                break
            f += 1
            e -= 1

        right_pal = True
        f, e = front, end - 1
        while f < e:
            if s[f] != s[e]:
                right_pal = False
                break
            f += 1
            e -= 1

        if left_pal or right_pal:
            print(1)  
        else:
            print(2)  
    else:
        print(0)  
