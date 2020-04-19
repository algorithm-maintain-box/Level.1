
def solution(cacheSize, arr):
    answer = 0
    tmp = []
    if cacheSize == 0:
        answer = int(str(len(arr))*5
        return answer
    for index in range(0, len(arr)):
        if arr[index] in tmp:
            answer = answer + 1
        elif len(tmp)< cacheSize:
            tmp.append(arr[index])
            answer = answer +  5  
        elif len(tmp)>cacheSize:
            tmp.pop(0)
            tmp.append(arr[index]) 
            answer = answer + 5
    return answer