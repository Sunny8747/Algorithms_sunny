// for making test env
#include <iostream>
#include <sstream>
// real input
// initial state
#include <string>
#include <vector>
// added
#include <algorithm>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes)
{
    int answer = 0;
    return answer;
}

bool programmers_io(string input1, int expected_result)
{
    vector<string> vec_input1;
    vector<vector<string>> clothes;
    stringstream ss;
    string tempStr;
    ss.str(input1);
    while (ss >> tempStr) {
        vec_input1.push_back(tempStr);
    }

    cout << "vec_input1 size : " << vec_input1.size() << endl;

    //result
    int result = solution(clothes);
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
    string input1 = "";
    int expected_result = 0;
    bool result = programmers_io(input1, expected_result);
}
