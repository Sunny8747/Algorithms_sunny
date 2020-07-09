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
#include <queue>

#define TIME_TEST false
#define LOG true

using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k)
{
    int answer = 0;
    // K 이상을 충족 시키는 최소 횟수 Sum
    // 매일 stock - 1
    // 오늘을 0일로 하고 포함이므로 총 stock 소모량은 K
    // stock = 4 -> 0일 ~ 3일후  최종 k-1일후 까지이므로 total_stock = k
    int SIZE = dates.size();
    priority_queue<int> pq;
    // stock == K일만큼 버티기가능
    // stock 만큼까지 dates supplies pq저장
    // top 한번빼기
    // stock 이 K이상될때까지 반복
    int temp_date = 0;
    int dates_count = 0;
    while (stock < k) {
        for (; dates_count < SIZE; dates_count++) {
            if (dates[dates_count] <= stock) {
                pq.push(supplies[dates_count]);
            }
            else {
                break;
            }
        }
        stock += pq.top();
        pq.pop();
        answer++;
    }

    return answer;
}

bool programmers_io(int i_input1, string s_input2, string s_input3, int i_input4, int expected_result)
{
    vector<int> vec_input1;
    vector<int> vec_input2;
    stringstream ss;
    string tempStr;

    ss.str(s_input2);
    while (ss >> tempStr) {
        vec_input1.push_back(stoi(tempStr));
    }

    ss.clear();
    ss.seekg(0);

    ss.str(s_input3);
    while (ss >> tempStr) {
        vec_input2.push_back(stoi(tempStr));
    }

    // result
    int result = solution(i_input1, vec_input1, vec_input2, i_input4);

    // Time Test
    if (TIME_TEST) {
        auto start = chrono::steady_clock::now();
        int count = 10000;
        while (count > 0) {
            count--;
            solution(i_input1, vec_input1, vec_input2, i_input4);
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
    int input1 = 4;
    string input2 = "4 10 15";
    string input3 = "20 5 10";
    int input4 = 30;
    int expected_result = 2;
    bool result = programmers_io(input1, input2, input3, input4, expected_result);
}
