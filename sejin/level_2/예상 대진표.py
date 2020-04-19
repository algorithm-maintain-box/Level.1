def solution(n, a , b):
    tmp = a //2 + a%2
    tmp2 = b //2 + b%2
    cnt = 1
    while tmp != tmp2:
        cnt= cnt + 1
        tmp = tmp //2 + tmp%2
        tmp2 = tmp2 //2 + tmp2%2
        if tmp == tmp2:
            return cnt
    return cnt
