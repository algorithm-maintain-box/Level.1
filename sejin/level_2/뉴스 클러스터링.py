def solution(str1, str2):
    answer = 0
    str1 = str1.upper()
    str2 = str2.upper()

    tmp1 = []
    tmp2 = []
    tmp3 = []
    tmp4 = []
    for index in range(0, len(str1)-1):
        tmp3.append(str1[index:index+2])
        if str(str1[index:index+2]).isalpha():
          tmp1.append(str1[index:index+2])
    for index in range(0, len(str2)-1):
        tmp4.append(str2[index :index+2]) 
        if str(str2[index:index+2]).isalpha():
          tmp2.append(str2[index :index+2]) 

    set1 = set(tmp3).union(set(tmp4))
    print(set1)
    set2 = set(tmp1).intersection(set(tmp2))
    print(set2)
    print( float(len(list(set2)))/len(list(set1)))
    answer = float(len(list(set2)))/len(list(set1)) * 65536
    return int(answer)

print(solution("aa1+aa2", "AAAA12"))
