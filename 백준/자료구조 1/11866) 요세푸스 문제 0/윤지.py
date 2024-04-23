from pprint import pprint
from collections import deque

N, K = map(int, input().split())

numbers = deque()
ans = []

for i in range(N):
    numbers.append(i+1)

#print(numbers)

while numbers:
    for i in range(0, K):
        #print(i)
        if i == K-1:
            ans.append(numbers[0])
            numbers.popleft()
        else:
            numbers.append(numbers[0])
            numbers.popleft()
            #print(numbers)

print("<", end="")
for i in range(len(ans)):
    if i == len(ans) - 1:
        print(f"{ans[i]}>", end="")
    else:
        print(f"{ans[i]}, ", end="")
