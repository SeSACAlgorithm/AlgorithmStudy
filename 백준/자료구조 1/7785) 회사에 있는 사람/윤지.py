line = int(input())
people = {}

for i in range(0, line):
    name, status = input().split()

    if status == "enter":
        people[name] = 1
    else :
        people[name] = 0

for person in sorted(people.keys(), reverse = True):
    if people[person] == 1:
        print(person)
