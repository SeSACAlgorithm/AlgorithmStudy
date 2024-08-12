
dict = {
    'A': 3, 'B': 2, 'C': 1, 'D': 2, 'E': 3,
    'F': 3, 'G': 3, 'H': 3, 'I': 1, 'J': 1,
    'K': 3, 'L': 1, 'M': 3, 'N': 3, 'O': 1,
    'P': 2, 'Q': 2, 'R': 2, 'S': 1, 'T': 2,
    'U': 1, 'V': 1, 'W': 2, 'X': 2, 'Y': 2,
    'Z': 1
}

S = input()

arr = []

for s in S:
    arr.append(dict[s])

while len(arr) != 1:
    tmp = []

    for i in range(0, len(arr) - 1, 2):
        num_sum = (arr[i] + arr[i + 1]) % 10
        tmp.append(num_sum)

    if len(arr) % 2 == 1:
        tmp.append(arr[-1])

    arr = tmp

if arr[0] % 2 == 1:
    print("I'm a winner!")
else:
    print("You're the winner?")
