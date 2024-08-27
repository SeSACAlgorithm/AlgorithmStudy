N = int(input())
P = list(map(int, input().split()))

P.sort()

tot_time = 0
cur_time = 0

for i in P:
    cur_time += i
    tot_time += cur_time

print(tot_time)
