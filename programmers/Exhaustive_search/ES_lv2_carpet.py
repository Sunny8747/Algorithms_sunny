from collections import deque
from itertools import combinations, permutations, product


def sol(brown, yellow):
    answer = []
    len_side = brown - 4
    xy_candidate = []
    for y_i in range(1, len_side - 2):
        for x_i in range(y_i, len_side - 2):
            if check_xy(x_i, y_i, len_side) and check_yellow(x_i, y_i, yellow):
                return [x_i + 2, y_i + 2]
    return answer


def check_xy(x, y, len_side):
    if (x + y) * 2 == len_side and x >= y:
        return True
    return False


def check_yellow(x, y, yellow):
    if x * y == yellow:
        return True
    return False


def check_ans(input1, input2, ex_ans):
    ans = sol(input1, input2)
    if ex_ans == ans:
        print("True")
    else:
        print("False : ", ans)


in1 = 10
in2 = 2
ex_ans = [4, 3]
check_ans(in1, in2, ex_ans)
# sol(var1)

