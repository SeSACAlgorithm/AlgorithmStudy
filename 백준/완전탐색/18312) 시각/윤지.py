N, K = map(int, input().split())

K = str(K)
count = 0

for hour in range(N + 1):
        for minute in range(60):
            for second in range(60):
                if K in f"{hour:02d}{minute:02d}{second:02d}":
                    count += 1

print(count)
