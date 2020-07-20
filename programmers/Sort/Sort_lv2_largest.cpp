// for making test env
#include <chrono>
#include <iostream>
#include <sstream>
// real input
// initial state
#include <string>
#include <vector>
// added
#include <algorithm>

#define TIME_TEST false
#define LOG true

using namespace std;

bool comp_first(int a, int b)
{
    string str_a = to_string(a);
    string str_b = to_string(b);
    return stoi(str_a.substr(0, 1)) > stoi(str_b.substr(0, 1));
}

bool comp_all(int a, int b)
{
    if (a == 0) {
        return false;
    }
    string str_a = to_string(a);
    string str_b = to_string(b);
    int ab = stoi(str_a + str_b);
    int ba = stoi(str_b + str_a);
    return ab > ba;
}

string solution(vector<int> numbers)
{
    string answer = "";
    sort(numbers.begin(), numbers.end(), comp_first);
    sort(numbers.begin(), numbers.end(), comp_all);
    for (auto iter = numbers.begin(); iter != numbers.end(); iter++) {
        answer += to_string((*iter));
        if (answer != "" && answer.length() == 1) {
            if (stoi(answer) == 0) {
                answer = "0";
                break;
            }
        }
    }
    return answer;
}

bool programmers_io(string input1, string expected_result)
{
    vector<int> vec_input1;
    stringstream ss;
    string tempStr;
    ss.str(input1);
    while (ss >> tempStr) {
        vec_input1.push_back(stoi(tempStr));
    }

    // result
    string result = solution(vec_input1);

    // Time Test
    if (TIME_TEST) {
        auto start = chrono::steady_clock::now();
        int count = 10000;
        while (count > 0) {
            count--;
            solution(vec_input1);
        }
        auto end = chrono::steady_clock::now();
        auto diff = end - start;
        cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
        cout << chrono::duration<double, nano>(diff).count() << " ns" << endl;
    }

    // get result
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
    //3 30 34 5 9 4 40 42
    string input1 = "3 30 34 5 9 4 40 42";
    string expected_result = "954424034330";
    bool result = programmers_io(input1, expected_result);
}
