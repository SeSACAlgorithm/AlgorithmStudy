import re

# 정규표현식
pattern = re.compile('^[A-F]?A+F+C+[A-F]?$')

for _ in range(int(input())):
    print('Good' if pattern.match(input()) == None else 'Infected!')


