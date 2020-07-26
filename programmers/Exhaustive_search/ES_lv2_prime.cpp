// for making test env
#include <chrono>
#include <iostream>
#include <sstream>
// real input
// initial state
#include <string>
#include <vector>
// added

#define TIME_TEST false
#define LOG true
using namespace std;

#define N_ELEMENTS(array) (sizeof(array) / sizeof((array)[0]))

vector<int> get_list(string numbers)
{
    vector<int> result;

    return result;
}

int solution(string numbers)
{
    int answer = 0;
    return answer;
}

bool programmers_io(string input1, int expected_result)
{
    // result
    int result = solution(input1);

    // Time Test
    if (TIME_TEST) {
        auto start = chrono::steady_clock::now();
        int count = 10000;
        while (count > 0) {
            count--;
            solution(input1);
        }
        auto end = chrono::steady_clock::now();
        auto diff = end - start;
        cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
        cout << chrono::duration<double, nano>(diff).count() << " ns" << endl;
    }

    // get result
    if (expected_result == result) {
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
    string input1 = "17";
    int expected_result = 3;
    bool result = programmers_io(input1, expected_result);
}
