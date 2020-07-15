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

vector<int> solution(vector<int> array, vector<vector<int>> commands)
{
    vector<int> answer;
    for (int i = 0; i < commands.size(); i++) {
        vector<int> vec_temp;
        for (int j = commands[i][0] - 1; j < commands[i][1]; j++) {
            vec_temp.push_back(array[j]);
        }
        sort(vec_temp.begin(), vec_temp.end());
        answer.push_back(vec_temp[commands[i][2] - 1]);
    }
    return answer;
}

bool programmers_io(string input1, string input2, string expected_result)
{
    vector<int> vec_input1;
    vector<vector<int>> vec_input2;
    vector<int> vec_result;
    stringstream ss;
    string tempStr;
    ss.str(input1);
    while (ss >> tempStr) {
        vec_input1.push_back(stoi(tempStr));
    }

    ss.clear();
    ss.seekg(0);
    ss.str(input2);
    for (int i = 0; i < 3; i++) {
        vector<int> vec_temp;
        for (int j = 0; j < 3; j++) {
            ss >> tempStr;
            vec_temp.push_back(stoi(tempStr));
        }
        vec_input2.push_back(vec_temp);
    }

    ss.clear();
    ss.seekg(0);
    ss.str(expected_result);
    while (ss >> tempStr) {
        vec_result.push_back(stoi(tempStr));
    }

    // result
    vector<int> result = solution(vec_input1, vec_input2);

    // Time Test
    if (TIME_TEST) {
        auto start = chrono::steady_clock::now();
        int count = 10000;
        while (count > 0) {
            count--;
            solution(vec_input1, vec_input2);
        }
        auto end = chrono::steady_clock::now();
        auto diff = end - start;
        cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
        cout << chrono::duration<double, nano>(diff).count() << " ns" << endl;
    }

    // get result
    if (result == vec_result) {
        cout << "Pass : ";
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << " ";
        }
        cout << endl;
        return true;
    }
    else {
        cout << "false result : ";
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
    string input1 = "1 5 2 6 3 7 4";
    string input2 = "2 5 3 4 4 1 1 7 3";
    string expected_result = "5 6 3";
    bool result = programmers_io(input1, input2, expected_result);
}
