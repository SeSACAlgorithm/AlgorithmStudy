#회문인지 판단
def palindrome(str):
    for i in range(0, len(str)):
        l = str[i]
        r = str[len(str) - i -1]
        check = True

        # 한 번이라도 다르면 회문 아님
        if l != r:
            check = False
            break
    return check


T = int(input())

answer = []
for t in range(T):
    K = int(input())
    check = False

    words = []
    for i in range(0, K):
        words.append(input())

    for i in range(K):
        for j in range(K):
            if i == j:
                continue
            str = words[i] + words[j]
            #print("test1")
            if palindrome(str):
                answer.append(str)
                check = True
                break

        if check:
            break

    if check == False:
        answer.append(0)

for i in answer:
    print(i)




