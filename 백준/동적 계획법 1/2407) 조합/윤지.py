n, m = map(int, input().split())

a , b , c = 1, 1, 1

for i in range(2, n+1):
    a = a * i

for i in range(2, m+1):
    b = b * i

for i in range(2, n-m+1):
    c = c * i
    
print(a // (b*c))
