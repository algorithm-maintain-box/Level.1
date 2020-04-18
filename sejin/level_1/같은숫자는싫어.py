def solution(s):
    answer = []
    tmp = s[0]
    answer.append(tmp)
    for i in range(1, len(s)):
        if tmp == s[i]: continue
        else:
            answer.append(s[i])
            tmp = s[i] 
    return answer  