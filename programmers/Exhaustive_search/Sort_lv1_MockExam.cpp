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

int grade(vector<int> answers, int* sequence, int sequence_size)
{
    printf("sequnce_size : %d\n", sequence_size);
    int result = 0;
    for (int i = 0; i < answers.size(); i++) {
        printf("i sequnce_size : %d\n", i % sequence_size);
        printf("sequnce[i sequnce_size] : %d\n", sequence[i % sequence_size]);
        if (answers[i] == sequence[i % sequence_size]) {
            result++;
        }
    }
    cout << "grade : " << result << endl;
    return result;
}

vector<int> solution(vector<int> answers)
{
    vector<int> answer;
    int sequence_1[5] = {1, 2, 3, 4, 5};
    int sequence_2[8] = {2, 1, 2, 3, 2, 4, 2, 5};
    int sequence_3[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    int result_1 = grade(answers, sequence_1, N_ELEMENTS(sequence_1));
    int result_2 = grade(answers, sequence_2, N_ELEMENTS(sequence_2));
    int result_3 = grade(answers, sequence_3, N_ELEMENTS(sequence_3));

    int max = 0;
    if (result_1 == result_2 && result_2 == result_3) {
        answer.push_back(1);
        answer.push_back(2);
        answer.push_back(3);
        return answer;
    }

    if (result_1 >= result_2 && result_1 >= result_3) {
        max = result_1;
        answer.push_back(1);
        if (result_1 == result_2) {
            answer.push_back(2);
        }
        else if (result_1 == result_3) {
            answer.push_back(3);
        }
    }
    else if (result_2 >= result_1 && result_2 >= result_3) {
        max = result_2;
        answer.push_back(2);
        if (result_2 == result_3) {
            answer.push_back(3);
        }
    }
    else {
        max = result_3;
        answer.push_back(3);
    }

    return answer;
}

bool programmers_io(string input1, string expected_result)
{
    vector<int> vec_input1;
    stringstream ss;
    string tempStr;
    ss.str(input1);
    while (ss >> tempStr) {
        vec_input1.push_back(stoi(tempStr));
    }

    vector<int> vec_result;
    ss.clear();
    ss.seekg(0);
    ss.str(expected_result);
    while (ss >> tempStr) {
        vec_result.push_back(stoi(tempStr));
    }

    // result
    vector<int> result = solution(vec_input1);

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
    if (vec_result == result) {
        cout << "Pass : ";
        for (int i = 0; i < result.size(); i++) {
            cout << result[i];
        }
        cout << endl;
        return true;
    }
    else {
        cout << "false result : ";
        for (int i = 0; i < result.size(); i++) {
            cout << result[i];
        }
        cout << endl;
        return false;
    }
}

int main()
{
    // making test set
    string input1 = "1 3 2 4 2";
    string expected_result = "1, 2, 3";
    bool result = programmers_io(input1, expected_result);
}
