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

bool less_test(int t_val1, int t_val2, int t_val3, int K)
{
    if (t_val1 >= K && t_val2 >= K && t_val3 >= K) {
        return true;
    }
    else {
        return false;
    }
}

int mix(int a, int b, int& mix_count)
{
    mix_count++;
    return (a + (b * 2));
}

int solution(vector<int> scoville, int K)
{
    int mix_count = 0;
    priority_queue<int> q;
    for (int i = 0; i < scoville.size(); i++) {
        q.push(-scoville[i]);
    }
    while (true) {
        int min = -q.top();
        q.pop();
        if (min >= K) {
            break;
        }
        if (q.empty()) {
            return -1;
        }
        int next_min = -q.top();
        q.pop();
        q.push(-mix(min, next_min, mix_count));
    }
    return mix_count;

    // if (SIZE > 2) {
    //     int a = 0;
    //     int b = 1;
    //     int c = 2;
    //     while (less_test(scoville[a], scoville[b], scoville[c], K)) {
    //         if (a == SIZE - 1 || b == SIZE - 1 || c == SIZE - 1) {
    //             if (scoville[a] > scoville[b] && scoville[a] > scoville[c]) {
    //                 if (scoville[b] < scoville[c]) {
    //                     scoville[c] = mix(scoville[b], scoville[c], mix_count);
    //                 }
    //                 else {
    //                     scoville[c] = mix(scoville[c], scoville[b], mix_count);
    //                 }
    //                 if (scoville[c] >= K && scoville[a] >= K) {
    //                     return mix_count;
    //                 }
    //                 else {
    //                     if (scoville[a] < scoville[c]) {
    //                         scoville[c] = mix(scoville[a], scoville[c], mix_count);
    //                     }
    //                     else {
    //                         scoville[c] = mix(scoville[c], scoville[a], mix_count);
    //                     }
    //                     if (scoville[c] >= K) {
    //                         return mix_count;
    //                     }
    //                     else {
    //                         return -1;
    //                     }
    //                 }
    //             }
    //             else if (scoville[b] > scoville[a] && scoville[b] > scoville[c]) {
    //                 if (scoville[a] < scoville[c]) {
    //                     scoville[c] = mix(scoville[a], scoville[c], mix_count);
    //                 }
    //                 else {
    //                     scoville[c] = mix(scoville[c], scoville[a], mix_count);
    //                 }
    //                 if (scoville[c] >= K && scoville[b] >= K) {
    //                     return mix_count;
    //                 }
    //                 else {
    //                     if (scoville[b] < scoville[c]) {
    //                         scoville[c] = mix(scoville[b], scoville[c], mix_count);
    //                     }
    //                     else {
    //                         scoville[c] = mix(scoville[c], scoville[b], mix_count);
    //                     }
    //                     if (scoville[c] >= K) {
    //                         return mix_count;
    //                     }
    //                     else {
    //                         return -1;
    //                     }
    //                 }
    //             }
    //             else {
    //                 if (scoville[a] < scoville[b]) {
    //                     scoville[b] = mix(scoville[a], scoville[b], mix_count);
    //                 }
    //                 else {
    //                     scoville[b] = mix(scoville[b], scoville[a], mix_count);
    //                 }
    //                 if (scoville[b] >= K && scoville[c] >= K) {
    //                     return mix_count;
    //                 }
    //                 else {
    //                     if (scoville[b] < scoville[c]) {
    //                         scoville[c] = mix(scoville[b], scoville[c], mix_count);
    //                     }
    //                     else {
    //                         scoville[c] = mix(scoville[c], scoville[b], mix_count);
    //                     }
    //                     if (scoville[c] >= K) {
    //                         return mix_count;
    //                     }
    //                     else {
    //                         return -1;
    //                     }
    //                 }
    //             }
    //         }
    //         if (scoville[a] > scoville[b] && scoville[a] > scoville[c]) {
    //             if (b > c) {
    //                 swap(b, c);
    //             }
    //             if (scoville[b] < scoville[c]) {
    //                 scoville[c] = mix(scoville[b], scoville[c], mix_count);
    //             }
    //             else {
    //                 scoville[c] = mix(scoville[c], scoville[b], mix_count);
    //             }
    //             b = c;
    //             if (a > c) {
    //                 c = a + 1;
    //             }
    //             else {
    //                 c = c + 1;
    //             }
    //         }
    //         else if (scoville[b] > scoville[a] && scoville[b] > scoville[c]) {
    //             if (a > c) {
    //                 swap(a, c);
    //             }
    //             if (scoville[a] < scoville[c]) {
    //                 scoville[c] = mix(scoville[a], scoville[c], mix_count);
    //             }
    //             else {
    //                 scoville[c] = mix(scoville[c], scoville[a], mix_count);
    //             }
    //             a = c;
    //             if (b > c) {
    //                 c = b + 1;
    //             }
    //             else {
    //                 c = c + 1;
    //             }
    //         }
    //         else {
    //             if (a > b) {
    //                 swap(a, b);
    //             }
    //             if (scoville[a] < scoville[b]) {
    //                 scoville[b] = mix(scoville[a], scoville[b], mix_count);
    //             }
    //             else {
    //                 scoville[b] = mix(scoville[b], scoville[a], mix_count);
    //             }
    //             a = b;
    //             if (c > b) {
    //                 b = c + 1;
    //             }
    //             else {
    //                 b = b + 1;
    //             }
    //         }
    //     }
    // }
    // else {
    //     if (scoville[0] >= K && scoville[1] >= K) {
    //         return 0;
    //     }
    //     if (mix(scoville[0], scoville[1], mix_count) >= K) {
    //         return mix_count;
    //     }
    //     else {
    //         return -1;
    //     }
    // }
    // return mix_count;
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
    int expected_result = 2;
    bool result = programmers_io(input1, input2, expected_result);
}
