import sys

dict = {}
tot_trees = 0

input_data = sys.stdin.read().splitlines()

for data in input_data:
    if data != '':
        tot_trees += 1
        if data not in dict:
            dict[data] = 1
        else:
            dict[data] += 1

for d in sorted(dict.keys()):
    percentage = (dict[d]/ tot_trees) * 100
    print(f"{d}{percentage: .4f}")
