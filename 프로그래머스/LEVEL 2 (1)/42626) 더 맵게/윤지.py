import heapq

def solution(scoville, K):
    answer = 0
    
    # 최소 힙으로 변경
    heapq.heapify(scoville)
    
    while len(scoville) > 1:
        # 첫번째
        first = heapq.heappop(scoville)
        if first >= K:
            break
        
        # 두번째 (섞어야 함)
        second = heapq.heappop(scoville)
        tmp = first + (second * 2)
        
        heapq.heappush(scoville, tmp)
        answer += 1
    
    # 안섞여짐
    if scoville[0] < K:
        answer = -1
    
    return answer
