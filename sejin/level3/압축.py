def solution(msg):
    set = {chr(i): i+1-ord('A') for i in range(ord('A'), ord('Z')+1)}
    answer = []
    a=0
    b=0
    while b < len(msg):
        if msg[a:b+1] in set:
            b += 1
        else:
            set[msg[a:b+1]] = len(set)+1
            answer.append(set[msg[a:b]])
            a = b
            b = b
    answer.append(set[msg[a:b+1]])
    return answer