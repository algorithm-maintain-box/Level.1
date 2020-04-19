# def solution(a):
#     answer = 0
#     for i in range(2, a+1):
#         cnt =0
#         for j in range(2, i+1):
#             if i%j==0:
#                 cnt+=1
#         if cnt==1:
#             answer += 1
#     return answer    

def solution(a):
  num = set(range(2,a+1))

  for i in range(2, a+1):
    if i in num:
      num -= set(range(2*i, a+1, i))
  return len(num)    
  
print(solution(10))