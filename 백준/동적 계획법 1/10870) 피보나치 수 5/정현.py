n = int(input())

num = [0,1]

for i in range(n):
    num.append(num[i]+num[i+1])

print(num[n])