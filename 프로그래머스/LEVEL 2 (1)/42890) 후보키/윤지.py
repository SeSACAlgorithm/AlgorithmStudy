from itertools import combinations

def solution(relation):
    answer = 0
    
    rows = len(relation)
    cols = len(relation[0])

    col_idx = range(cols)

    candidate_keys = []

    for r in range(1, cols + 1):
        for combination in combinations(col_idx, r):
            unique_check = {tuple(item[col] for col in combination) for item in relation}

            if len(unique_check) == rows:  
                if not any(set(candidate).issubset(combination) for candidate in candidate_keys):
                    candidate_keys.append(combination)
    
    answer = len(candidate_keys)
    return answer
