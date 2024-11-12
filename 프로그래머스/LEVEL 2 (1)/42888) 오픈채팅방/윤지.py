def solution(record):
    arr = []
    names = {}
    
    for r in record:
        tmp_arr = r.split()
        command = tmp_arr[0] # command
        uid = tmp_arr[1]     # id
        
        if command == "Enter":
            nickname = tmp_arr[2]
            names[uid] = nickname
            arr.append((uid, "님이 들어왔습니다."))
        elif command == "Leave":
            arr.append((uid, "님이 나갔습니다."))
        else:
            nickname = tmp_arr[2]
            names[uid] = nickname
            
    answer = [names[uid] + message for uid, message in arr]
    
    return answer
