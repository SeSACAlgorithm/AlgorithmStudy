N = int(input())
books = {}

for i in range(N):
    book = input()

    if book in books:
        books[book] += 1
    else:
        books[book] = 1

sorted_books = sorted(books.keys())
maxValue = max(books.values())
maxKey = None

for key in sorted_books:
    if books[key] == maxValue:
        maxKey = key
        break

print(maxKey)