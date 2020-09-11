from collections import deque
from itertools import combinations, permutations, product


def sol(number, k):
    answer = []
    length = len(number)
    index = 0
    temp_k = 0
    while index < length:
        if not answer:
            answer.append(number[index])
            index += 1
            continue
        if number[index] > answer[-1] and temp_k < k:
            for ans_elem in reversed(list(answer)):
                if number[index] > ans_elem:
                    answer.pop()
                    temp_k += 1
                    if temp_k == k:
                        break
                else:
                    break
            answer.append(number[index])
            index += 1
        else:
            number[index]
            answer.append(number[index])
            index += 1
    if index == length and len(answer) > length - k:
        for i in range(len(answer) - length + k):
            answer.pop()
    answer = "".join(answer)
    return answer


def check_ans(input1, input2, ex_ans):
    ans = sol(input1, input2)
    if ex_ans == ans:
        print("True")
    else:
        print("False : ", ans)


in1 = "1924"
in2 = 2
ex_ans = "94"
check_ans(in1, in2, ex_ans)
# sol(var1)

