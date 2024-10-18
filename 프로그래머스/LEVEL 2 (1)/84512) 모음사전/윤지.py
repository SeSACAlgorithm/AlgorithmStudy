from itertools import product

def solution(word):
    answer = 0
    
    arr = ['A', 'E', 'I', 'O', 'U']
    words = []
    
    for i in range(1, 6):
        words.extend([''.join(p) for p in product(arr, repeat=i)])        
        
    words.sort()
    
    answer = words.index(word) + 1
    
    return answer
