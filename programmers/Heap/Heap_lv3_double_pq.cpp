// for making test env
#include <chrono>
#include <iostream>
#include <sstream>
// real input
// initial state
#include <string>
#include <vector>
// added
#include <list>

#define TIME_TEST true
#define LOG true

using namespace std;

void push_pq(list<int>& pq, int val)
{
    for (auto iter = pq.begin(); iter != pq.end(); iter++) {
        if (val <= (*iter)) {
            pq.insert(iter, val);
            return;
        }
    }
    pq.push_back(val);
}

vector<int> solution(vector<string> operations)
{
    vector<int> answer;
    list<int> doulbe_pq;

    for (auto iter = operations.begin(); iter != operations.end(); iter++) {
        if (*iter == "D 1") {
            if (!doulbe_pq.empty()) {
                doulbe_pq.pop_back();
            }
        }
        else if (*iter == "D -1") {
            if (!doulbe_pq.empty()) {
                doulbe_pq.pop_front();
            }
        }
        else {
            string temp_str = (*iter).substr(2, (*iter).length() - 2);
            push_pq(doulbe_pq, stoi(temp_str));
        }
    }

    if (doulbe_pq.empty()) {
        answer.push_back(0);
        answer.push_back(0);
        return answer;
    }
    else {
        answer.push_back(doulbe_pq.back());
        answer.push_back(doulbe_pq.front());
        return answer;
    }

    return answer;
}

bool programmers_io(vector<string> s_input1, vector<int> expected_result)
{
    // result
    vector<int> result = solution(s_input1);

    // Time Test
    if (TIME_TEST) {
        auto start = chrono::steady_clock::now();
        int count = 10000;
        while (count > 0) {
            count--;
            solution(s_input1);
        }
        auto end = chrono::steady_clock::now();
        auto diff = end - start;
        cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
        cout << chrono::duration<double, nano>(diff).count() << " ns" << endl;
    }

    // get result
    if (result == expected_result) {
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
    vector<string> input1;
    // I 7,I 5,I -5,D -1
    input1.push_back("I 16");
    input1.push_back("I -5643");
    input1.push_back("D -1");
    input1.push_back("D 1");
    input1.push_back("D 1");
    input1.push_back("I 123");
    input1.push_back("D -1");

    vector<int> expected_result;

    expected_result.push_back(0);
    expected_result.push_back(0);

    bool result = programmers_io(input1, expected_result);
}
