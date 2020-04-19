def solution(n):
    for i in range(1, n//2): 
        if n == i * i:
            return (i+1)**2
    return -1