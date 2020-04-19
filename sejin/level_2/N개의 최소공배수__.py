def gcd(a,b):
    if(b==0):
        return a
    else:
        return gcd(b, a%b)
    
def solution(arr):
    answer = gcd(arr[0], arr[1])
    for i in range(2, len(arr)):
        answer = gcd(answer, arr[i])
    tmp = 1
    for j in range(0, len(arr)):
        tmp = tmp*arr[j]
    return tmp // answer