from itertools import permutations
def solution(numbers):
    tmp = set()
    for i in range(len(numbers)):
        tmp |= set(map(int, map("".join, permutations(list(numbers), i + 1))))
    tmp -= set(range(0, 2))
    for i in range(2, int(max(tmp) ** 0.5) + 1):
        tmp -= set(range(i * 2, max(tmp) + 1, i))
    return len(tmp)