// for making test env
#include <iostream>
#include <sstream>
// real input
// initial state
#include <string>
#include <vector>

using namespace std;

#define N_ELEMENTS(array) (sizeof(array) / sizeof((array)[0]))

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    vector<int> answer;
    int max_day = 0;
    int work_count = 0;
    for (int i = 0; i < progresses.size(); i++) {
        float temp1 = 100 - progresses[i];
        float temp2 = speeds[i];
        int temp_day = (int)ceil(temp1 / temp2);
        if (max_day == 0) {
            max_day = temp_day;
            work_count++;
        }
        else {
            if (max_day < temp_day) {
                max_day = temp_day;
                answer.push_back(work_count);
                work_count = 1;
            }
            else {
                work_count++;
            }
        }
    }
    answer.push_back(work_count);
    return answer;
}

bool programmers_io(string s_input1, string s_input2, string expected_result)
{
    vector<int> vi_input1;
    vector<int> vi_input2;
    vector<int> ex_result;

    stringstream ss;
    string tempStr;
    ss.str(s_input1);
    while (ss >> tempStr) {
        vi_input1.push_back(stoi(tempStr));
    }
    cout << "input1 size : " << vi_input1.size() << endl;

    ss.clear();
    ss.seekg(0);
    ss.str(s_input2);
    cout << s_input2 << endl;
    while (ss >> tempStr) {
        vi_input2.push_back(stoi(tempStr));
    }
    cout << "input2 size : " << vi_input2.size() << endl;

    ss.clear();
    ss.seekg(0);
    ss >> expected_result;
    while (ss >> tempStr) {
        ex_result.push_back(stoi(tempStr));
    }
    cout << "ex_result size : " << ex_result.size() << endl;

    //result
    vector<int> result = solution(vi_input1, vi_input2);
    if (result == ex_result) {
        cout << "Pass : " << endl;
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
    string s_input1 = "93 30 55";
    string s_input2 = "1 30 5";
    string i_expected_result = "2 1";

    bool result = programmers_io(s_input1, s_input2, i_expected_result);
}
