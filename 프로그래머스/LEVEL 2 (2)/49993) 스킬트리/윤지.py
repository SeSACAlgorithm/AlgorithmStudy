from collections import deque 

def solution(skill, skill_trees):
    answer = 0

    for skill_tree in skill_trees:
        skill_queue = deque(skill)

        for s in skill_tree:
            if s in skill_queue:
                if s != skill_queue.popleft():
                    break
        else:
            answer += 1

    return answer
