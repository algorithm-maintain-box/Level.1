def solution(s):
    answer=''
    a = list(s)
    tmp = int(len(a)/2)
    if len(a)%2 == 0:
        answer = answer+a[tmp-1]
        answer = answer+a[tmp]
    else:
        answer = answer+a[tmp]  
    return answer

