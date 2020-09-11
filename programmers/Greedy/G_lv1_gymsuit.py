from collections import deque
from itertools import combinations, permutations, product


def sol(n, lost, reserve):
    answer = 0
    lost.sort()
    reserve.sort()
    for lost_s in list(lost):
        try:
            reserve.index(lost_s)
        except:
            pass
        else:
            lost.remove(lost_s)
            reserve.remove(lost_s)
    for lost_s in lost:
        for reserve_s in reserve:
            if reserve_s == lost_s - 1 or reserve_s == lost_s + 1:
                reserve.remove(reserve_s)
                answer += 1
                break
            elif reserve_s > lost_s + 1:
                break
    answer = n - len(lost) + answer
    return answer


def check_ans(input1, input2, input3, ex_ans):
    ans = sol(input1, input2, input3)
    if ex_ans == ans:
        print("True")
    else:
        print("False : ", ans)


in1 = 5
in2 = [2, 4]
in3 = [1, 2, 3]
ex_ans = 4
check_ans(in1, in2, in3, ex_ans)
# sol(var1)

