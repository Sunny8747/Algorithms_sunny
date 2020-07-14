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
#include <cmath>
#include <queue>

#define TIME_TEST false
#define LOG true

using namespace std;

int solution(vector<vector<int>> jobs)
{
    int answer = 0;
    int SIZE = jobs.size();
    sort(jobs.begin(), jobs.end());
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    int current_time = 0;
    int job_counter = 0;
    while (true) {
        for (; job_counter < SIZE; job_counter++) {
            if (current_time < jobs[job_counter][0]) {
                break;
            }
            pq.push(make_pair(jobs[job_counter][1], jobs[job_counter][0]));
        }
        if (job_counter != SIZE && pq.empty()) {
            current_time = jobs[job_counter][0];
        }
        else {
            current_time = current_time + pq.top().first;
            answer = answer + current_time - pq.top().second;

            // LOG
            if (LOG) {
                cout << "--- LOG ---" << endl;
                cout << "pq top : " << pq.top().first << endl;
                cout << "jobs counter : " << job_counter << endl;
                cout << "current_time : " << current_time << endl;
                cout << "answer : " << answer << endl;
            }

            pq.pop();
            if (job_counter == SIZE && pq.empty()) {  // problem why job_counter is 3
                break;
            }
        }
    }

    if (LOG) {
        cout << "----- Last LOG -----" << endl;
        cout << "time : " << current_time << endl;
        cout << "answer : " << answer << endl;
        cout << "SIZE : " << SIZE << endl;
    }

    answer = floor((double)answer / SIZE);
    return answer;
}

bool programmers_io(string input1, int expected_result)
{
    vector<vector<int>> vec_input1;
    stringstream ss;
    string tempStr;
    ss.str(input1);
    int counter = 0;
    int out_bit = 0;
    for (int i = 0; i < 3; i++) {
        vector<int> vec_temp;
        for (int j = 0; j < 2; j++) {
            ss >> tempStr;
            cout << stoi(tempStr) << endl;
            vec_temp.push_back(stoi(tempStr));
        }
        vec_input1.push_back(vec_temp);
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
    string input1 = "0 3 1 9 2 6";
    int input2 = 7;
    int expected_result = 9;
    bool result = programmers_io(input1, expected_result);
}
