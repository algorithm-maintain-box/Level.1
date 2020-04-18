def solution(skill, skill_tree):
    cnt = 0
    for tree in skill_tree:
        a = [skill.index(i) for i in tree if i in skill]
        a_ = sorted(a)
        if a == a_ and all(i in tree for i in skill[:len(a)]):
            cnt += 1
    return cnt