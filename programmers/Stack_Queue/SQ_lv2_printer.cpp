// for making test env
#include <iostream>
#include <sstream>
// real input
// initial state
#include <string>
#include <vector>

using namespace std;

#define N_ELEMENTS(array) (sizeof(array) / sizeof((array)[0]))

int solution(vector<int> priorities, int location)
{
    int answer = 0;
    int SIZE = priorities.size();
    int* temp_arr = new int[SIZE];
    for (int i = 0; i < SIZE; i++) {
        temp_arr[i] = priorities[i];
    }

    int target_pri = priorities[location];
    int counter = 0;
    int start_loc = 0;
    int temp_max_pri;
    int temp_max_loc;
    while (true) {
        counter++;
        // 1. exist highest
        // 2. exist same
        // 3. target is max
        temp_max_pri = 0;
        temp_max_loc = 0;
        for (int i = 0; i < SIZE; i++) {
            int temp_i = i + start_loc;
            if ((temp_i) >= SIZE) {
                if (temp_arr[temp_i - SIZE] > temp_max_pri) {
                    temp_max_pri = temp_arr[temp_i - SIZE];
                    temp_max_loc = temp_i - SIZE;
                }
            }
            else {
                if (temp_arr[temp_i] > temp_max_pri) {
                    temp_max_pri = temp_arr[temp_i];
                    temp_max_loc = temp_i;
                }
            }
        }
        if (temp_max_loc == location) {
            answer = counter;
            break;
        }
        else {
            temp_arr[temp_max_loc] = 0;
            start_loc = temp_max_loc;
        }
    }
    delete[] temp_arr;
    return answer;
}

bool programmers_io(string s_input1, int i_input2, int expected_result)
{
    vector<int> vi_input1;

    stringstream ss;
    string tempStr;
    ss.str(s_input1);
    while (ss >> tempStr) {
        vi_input1.push_back(stoi(tempStr));
    }
    cout << "input1 size : " << vi_input1.size() << endl;

    //result
    int result = solution(vi_input1, i_input2);
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
    string s_input1 = "1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 2";
    int i_input2 = 97;
    int i_expected_result = 99;

    bool result = programmers_io(s_input1, i_input2, i_expected_result);
    return result;
}
