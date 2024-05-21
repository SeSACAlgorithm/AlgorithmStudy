S = input()

stack = []
check = False
ans = ''

for s in S:
    # 공백 -> 스택 초기화
    if s == " ":
        while stack:
            ans += stack.pop()
        ans += s
    elif s == "<":
        while stack:
            ans += stack.pop()
        check = True
        ans += s

    elif s == ">":
        check = False
        ans += s

    elif check:
        ans += s

    # 밖 단어 뒤집음
    else:
        stack.append(s)

# 출력
while stack:
    ans += stack.pop()
print(ans)
