// for making test env
#include <iostream>
#include <sstream>
// real input
// initial state
#include <stack>
#include <string>
#include <vector>

using namespace std;

int solution(string arrangement)
{
    int answer = 0;
    vector<int> lazer_pos;
    stack<int> bar;
    for (int i = 0; i < arrangement.length(); i++) {
        if (arrangement[i] == '(') {
            if (arrangement[i + 1] == ')') {
                lazer_pos.push_back(i);
            }
        }
    }

    auto iter_lazor = lazer_pos.begin();
    for (int i = 0; i < arrangement.length(); i++) {
        // skip lazor pos
        if (i == (*iter_lazor)) {
            i++;
            iter_lazor++;
        }
        else {
            if (arrangement[i] == '(') {
                bar.push(i);
            }
            else {
                int bar_start = bar.top();
                bar.pop();
                for (auto iter = lazer_pos.begin(); iter != lazer_pos.end(); iter++) {
                    if ((*iter) > i) {
                        break;
                    }
                    if ((*iter) > bar_start && (*iter) < i) {
                        answer++;
                    }
                }
                answer++;
            }
        }
    }
    return answer;
}

bool programmers_io(string input1, int expected_result)
{
    //result
    int result = solution(input1);
    if (result == expected_result) {
        cout << "Pass : " << result << endl;
        return true;
    }
    else {
        cout << "false result : " << result << endl;
        return false;
    }
}

int main()
{
    // making test set
    string input1 = "()(((()())(())()))(())";
    int expected_result = 17;
    bool result = programmers_io(input1, expected_result);
}
