def solution(number, k):
    number = list(number)
    cnt = 0
    while cnt< k:
        for i in range(0, len(number)-1):
            if int(number[i]) < int(number[i+1]):
                print(number[i])
                del number[i]
                cnt += 1
                break
    answer = "".join(number)
    return answer