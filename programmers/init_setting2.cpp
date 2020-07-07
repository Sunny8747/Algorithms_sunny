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
#include <iterator>
#include <map>
using namespace std;

#define N_ELEMENTS(array) (sizeof(array) / sizeof((array)[0]))

bool solution(vector<string> phone_book)
{
    bool answer = true;
    return answer;
}

bool programmers_io(string* input1, int size_input, bool expected_result)
{
    vector<string> vec_input1;
    for (int i = 0; i < size_input; i++) {
        vec_input1.push_back(input1[i]);
    }

    //result

    auto start = chrono::steady_clock::now();
    bool result = solution(vec_input1);
    int count = 10000;
    while (count > 0) {
        count--;
        solution(vec_input1);
    }
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    cout << chrono::duration<double, nano>(diff).count() << " ns" << endl;

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
    string input1[] = {"119", "97674223", "1195524421"};
    bool expected_result = false;

    bool result = programmers_io(input1, N_ELEMENTS(input1), expected_result);
}
