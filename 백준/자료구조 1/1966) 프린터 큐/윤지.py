from collections import deque

T = int(input())

for _ in range(T):
    N, M = map(int, input().split())

    arr = list(map(int, input().split()))

    que = deque([(i, p) for i, p in enumerate(arr)])
    ans = 0

    while que:
        cur = que.popleft()

        flag = False
        for q in list(que):
            if cur[1] < q[1]:
                flag = True

        # 중요도 더 높은 경우
        if flag:
            que.append(cur)
        else:
            ans += 1
            if cur[0] == M:
                print(ans)
                break
