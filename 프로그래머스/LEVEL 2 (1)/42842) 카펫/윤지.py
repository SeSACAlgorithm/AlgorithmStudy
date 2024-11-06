def solution(brown, yellow):
    answer = []
    tot_tiles = brown + yellow
    
    for h in range(1, tot_tiles):
        if tot_tiles % h == 0:
            width = tot_tiles // h
            if (width - 2) * (h - 2) == yellow:
                if width >= h:
                    answer = [width, h]
                else:
                    answer = [h, width]
                
    return answer
