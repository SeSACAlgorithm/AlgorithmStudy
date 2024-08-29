Q = input()

numbers = Q.split('-')
#print(numbers)

tmp = sum(map(int, numbers[0].split('+')))

for n in numbers[1:]:
    tmp -= sum(map(int, n.split('+')))

print(tmp)
