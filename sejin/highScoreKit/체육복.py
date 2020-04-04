def solution(n, lost, reserve):
    answer = 0
    tmp =[1]*(n+2)
    tmp[0] = 0
    tmp[n+1] = 0
    for i in reserve:
        tmp[i] += 1
    for i in lost:
        tmp[i]-=1
        if tmp[i-1] == 2:
            tmp[i-1]-=1
            tmp[i]=+1
        elif tmp[i+1] == 2:
            tmp[i+1] -=1
            tmp[i]+=1
    for i in tmp:
        if i >0:
            answer +=1
            
    return answer