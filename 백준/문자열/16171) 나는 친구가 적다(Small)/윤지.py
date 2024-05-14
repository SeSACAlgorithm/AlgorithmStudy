S = input()
K = input()

ans = 1
tmp = "".join([i for i in S if not i.isdigit()])
k = "".join(K)

if tmp.find(K) == -1:
    ans = 0

print(ans)
