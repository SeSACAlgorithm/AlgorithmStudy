N = int(input())

Q = input()
arr = [0] * N
stack = []

for i in range(N):
    arr[i] = int(input())

for q in Q:
    if 'A' <= q <= 'Z':
        stack.append(arr[ord(q) - ord('A')])
    else:
        b = stack.pop()
        a = stack.pop()
        if q == '+':
            stack.append(a + b)
        elif q == '-':
            stack.append(a - b)
        elif q == '*':
            stack.append(a * b)
        elif q == '/':
            stack.append(a / b)

print(f"{stack[0]:.2f}")
