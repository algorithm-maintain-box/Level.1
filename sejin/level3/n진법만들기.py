def convert(n, base):
    T = "0123456789ABCDEF"
    q, r = divmod(n, base)
    if q == 0:
        return T[r]
    else:
        return convert(q, base) + T[r]

set = {10 : 'A' , 11 : 'B', 12:'C', 13:'D', 14:'E', 15:'F' }

# def solution(n, t, m, p):
#     answer = ''
#     return answer

#���� n, �̸� ���� ������ ���� t, ���ӿ� �����ϴ� �ο� m, Ʃ���� ���� p #�� �־�����.

def solution(n, t, m, p):
    answer = ''

    tmp=list()
    i = 0
    while len(tmp) <= t*2:
        if i in set:
            tmp.extend(set[i])
        else:
            tmp.extend(convert(i,n))
        i = i + 1

    print(tmp)

    answer = ''
    for i in range(0, len(tmp)):
        if i%m == p-1:
            answer = answer + tmp[i]
        if len(answer) == t:
            break    
    return answer