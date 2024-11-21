import sys

tc = sys.stdin.read().strip().split("\n")

for t in tc:
    s, t = t.split()

    r, l = 0, 0
    while r < len(s) and l < len(t):
        if s[r] == t[l]:
            r += 1
        l += 1

    if r == len(s):
        print("Yes")
    else:
        print("No")
