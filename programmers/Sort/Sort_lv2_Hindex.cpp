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

bool comp_dec(int a, int b)
{
    return a > b;
}

int solution(vector<int> citations)
{
    // n = [1, 1000]
    // h = [0, 10000]
    int answer = citations.size();
    sort(citations.begin(), citations.end(), comp_dec);
    for (int i = 0; i < citations.size(); i++) {
        if (citations[i] < i + 1) {
            return i;
        }
    }
    return answer;
}

bool programmers_io(string input1, int expected_result)
{
    vector<int> vec_input1;
    stringstream ss;
    string tempStr;
    ss.str(input1);
    while (ss >> tempStr) {
        vec_input1.push_back(stoi(tempStr));
    }

    // result
    int result = solution(vec_input1);

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
    string input1 = "3 0 6 1 5";
    int expected_result = 3;
    bool result = programmers_io(input1, expected_result);
}
