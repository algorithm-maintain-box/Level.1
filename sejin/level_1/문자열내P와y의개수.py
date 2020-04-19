import collections

def solution(s):
    tmp = list(s.upper())
    result = collections.Counter(tmp)
    if result["P"] == result["Y"]:
        return True
    else:
        return False