// for making test env
#include <iostream>
#include <sstream>
// real input
// initial state
#include <string>
#include <vector>
// added
#include <algorithm>
#include <iterator>
#include <queue>
using namespace std;

#define N_ELEMENTS(array) (sizeof(array) / sizeof((array)[0]))

vector<int> solution(vector<int> heights)
{
    vector<int> answer;
    int max_pos = 1;
    int max_heights = 0;
    for (int i = 0; i < heights.size(); i++) {
        if (i == 0) {
            max_heights = heights[0];
            answer.push_back(0);
        }
        if (max_heights < heights[i]) {
            max_pos = i + 1;
            max_heights = heights[i];
        }
        for (int j = i - 1; j >= max_pos - 1; j--) {
            if (heights[i] < heights[j]) {
                answer.push_back(j + 1);
                break;
            }
        }
        if (answer.size() != i + 1) {
            answer.push_back(0);
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
    ss.seekg(0);
    ss.str(expected_result);
    while (ss >> tempStr) {
        ex_result.push_back(stoi(tempStr));
    }

    //result
    vector<int> result = solution(vi_input);
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
    string s_input3 = "6 9 5 7 4";
    string i_expected_result = "0 0 2 2 4";

    bool result = programmers_io(s_input3, i_expected_result);
}
