for t in range(1, int(input()) + 1):

    N = int(input())
    nums = sorted(list(map(int, input().split())))
    ans = []

    for i in range(10):                     
        if i % 2 == 1:                     
            ans.append(nums.pop(0))        
        elif i % 2 == 0:                   
            ans.append(nums.pop())         
            
    print(f'#{t}', end = ' ')
    print(*ans)
