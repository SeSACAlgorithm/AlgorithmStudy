small = []

for i in range(0,9):
    tmp = int(input())
    small.append(tmp)

tot = sum(small)
check = False
for i in range(0,len(small)):
    for j in range(i+1,len(small)):
        if tot - small[i] - small[j] == 100 :
            num1, num2 = small[i], small[j]
            small.remove(num1)
            small.remove(num2)

            check = True
            small.sort()
            for k in range(0, len(small)):
                print(small[k])
            break
    if check:
        break


#print(sum(small))
