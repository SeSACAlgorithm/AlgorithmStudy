import sys
input = sys.stdin.readline

N = int(input())

books = {} # 책 이름 key, 개수 value 저장하는 딕셔너리

for i in range(N):
    title = input()
    if title in books:
        books[title] += 1 # 이미 books에 책이 존재한다면, 해당 책의 개수를 1 증가
    else:
        books[title] = 1 # 책이 books에 없다면, 새로운 키로 추가하고 그 값을 1로 설정

best = max(books.values()) # 가장 많이 등장한 책의 개수
arr = [] # 최대 등장 횟수를 가진 책의 이름들 저장할 리스트

for j, k in books.items():
    if k == best: # 현재 책의 개수가 best와 같다면
        arr.append(j) # 책의 이름 j를 리스트에 추가

best_book = sorted(arr) # 가장 많이 팔린 책이 여러 개일 경우에는 사전 순으로 가장 앞서는 제목을 출력 하기 위해 정렬
print(best_book[0])