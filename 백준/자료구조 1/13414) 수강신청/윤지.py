from collections import OrderedDict
import sys
input = sys.stdin.read
data = input().splitlines()

k, l = map(int, data[0].split())
student_order = OrderedDict()

for i in range(1, l + 1):
    student_id = data[i].strip()
    if student_id in student_order:
        del student_order[student_id]
    student_order[student_id] = None

for student_id in list(student_order.keys())[:k]:
    print(student_id)
