def solution(people, limit):
    sum = 0
    tmp = sorted(people)
    first = 0
    last = len(tmp)-1
    cnt = 0
    anwer = 0
    while(first < last):
        if(tmp[first] + tmp[last] <= limit):
            cnt += 1
            first += 1
            last -= 1
            
        else:
            last -= 1
    answer = len(people)-cnt
    return answer