a, b, c, d, e, f = map(int, input().split())

tmp = a * e - b * d
x = (e * c - b * f) // tmp
y = (a * f - d * c) // tmp

print(f"{x} {y}")
