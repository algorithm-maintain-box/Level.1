def solution(numbers, target):
    global answer 
    answer = 0
    cnt =0 
    operator(numbers, 0, target)
    return answer
    
def operator(numbers,index,target):
    if index > len(numbers)-1:
        if sum(numbers) == target:
            global answer 
            answer += 1
        return
    else:
        operator(numbers, index+1, target)
        numbers[index] *= -1 
        operator(numbers, index+1, target)