def solution(record):
    answer = []  
    tmp = []
    arr = []
    for i in record :
        tmp = i.split()
        arr.append(tmp)
    id = {}
    for x in arr:
        if x[0] == "Enter":
            id[x[1]] = x[2]
        if x[0] == "Change":
            id[x[1]] = x[2]
    for x in arr:
        if x[0] == "Enter":
            answer.append(id[x[1]] + "���� ���Խ��ϴ�.")

        if x[0] == "Leave":
            answer.append(id[x[1]]+ "���� �������ϴ�.")  
    return answer