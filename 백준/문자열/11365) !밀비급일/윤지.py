import sys
input = sys.stdin.read

data = input().strip().split('\n')
    
for line in data:
    if line == "END":
        break
    print(line[::-1])
