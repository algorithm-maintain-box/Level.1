def solution(x):
  tmp = sum(map(int, str(x)))
  if x%tmp ==0:
    return True
  else:
    return False  