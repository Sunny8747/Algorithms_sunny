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
#include <map>

using namespace std;

int solution(vector<string> clothes)
{
}

bool programmers_io(string input1, int expected_result)
{
    vector<string> vec_input1;
    stringstream ss;
    string tempStr;
    ss.str(input1);
    while (ss >> tempStr) {
        vec_input1.push_back(tempStr);
    }

    //result
    auto start = chrono::steady_clock::now();
    int result = solution(vec_input1);
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
    string input1 = "";
    int expected_result = 0;
    bool result = programmers_io(input1, expected_result);
}
