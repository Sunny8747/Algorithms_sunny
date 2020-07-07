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
using namespace std;

#define N_ELEMENTS(array) (sizeof(array) / sizeof((array)[0]))

vector<int> solution(vector<int> prices)
{
    vector<int> answer;
    int SIZE = prices.size();
    bool checkbit = false;
    for (int i = 0; i < SIZE; i++) {
        checkbit = true;
        for (int j = 1; j + i < SIZE; j++) {
            if (prices[i + j] < prices[i]) {
                answer.push_back(j);
                checkbit = false;
                break;
            }
        }
        if (checkbit) {
            answer.push_back(SIZE - 1 - i);
        }
    }
    return answer;
}

bool programmers_io(string s_input, string expected_result)
{
    vector<int> vi_input;
    vector<int> ex_result;

    stringstream ss;
    string tempStr;
    ss.str(s_input);
    while (ss >> tempStr) {
        vi_input.push_back(stoi(tempStr));
    }
    cout << "input1 size :" << vi_input.size() << endl;

    ss.clear();
    ss.seekg(0);
    ss.str(expected_result);
    while (ss >> tempStr) {
        ex_result.push_back(stoi(tempStr));
    }
    cout << "ex_result size :" << ex_result.size() << endl;

    //result
    auto start = chrono::steady_clock::now();
    vector<int> result = solution(vi_input);
    int count = 10000;
    while (count > 0) {
        count--;
        solution(vi_input);
    }
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    cout << chrono::duration<double, nano>(diff).count() << " ns" << endl;
    if (result == ex_result) {
        cout << "Pass : " << endl;
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << " ";
        }
        return true;
    }
    else {
        cout << "false result : " << endl;
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << " ";
        }
        cout << endl;
        return false;
    }
}

int main()
{
    // making test set
    string s_input3 = "2 3 4 5 1";
    string i_expected_result = "4 3 2 1 0";

    bool result = programmers_io(s_input3, i_expected_result);
}
