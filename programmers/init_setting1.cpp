// for making test env
#include <chrono>
#include <iostream>
#include <sstream>
// real input
// initial state
#include <string>
#include <vector>
// added

#define TIME_TEST true
#define LOG true

using namespace std;

int solution(vector<int> scoville, int K)
{
    int answer = 0;
    return answer;
}

bool programmers_io(string input1, int i_input2, int expected_result)
{
    vector<int> vec_input1;
    stringstream ss;
    string tempStr;
    ss.str(input1);
    while (ss >> tempStr) {
        vec_input1.push_back(stoi(tempStr));
    }

    // result
    int result = solution(vec_input1, i_input2);

    // Time Test
    if (TIME_TEST) {
        auto start = chrono::steady_clock::now();
        int count = 10000;
        while (count > 0) {
            count--;
            solution(vec_input1, i_input2);
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
    string input1 = "1 2 3 9 10 12";
    int input2 = 7;
    int expected_result = 0;
    bool result = programmers_io(input1, input2, expected_result);
}
