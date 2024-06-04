def solution(n, words):
    answer = []
    
    used_words = set()  
    previous_word = words[0][0]
    
    chk = False
    
    for i, word in enumerate(words):
        #조건 확인
        if word in used_words or word[0] != previous_word[-1]:
            answer.append((i % n) + 1)
            answer.append((i // n) + 1)
            chk = True
            break
        
        # 중복 단어 체크
        used_words.add(word)
        # 마지막 문자 갱신
        previous_word = word
    
    if chk == False:
        answer = [0, 0]
            

    return answer
