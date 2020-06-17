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

template <class T1, class T2>
bool programmers_io(T1 input1, T1 input2, T2 expected_result);

vector<string> solution(vector<string> participant, vector<string> completion)
{
    vector<string> ans;
    return ans;
}

int main(int argc, char** argv)
{
    // making test set
    string input1 = "";
    string input2 = "";
    string expected_result = "";
    bool result = programmers_io(input1, input2, expected_result);
}

template <class T1, class T2>
bool programmers_io(T1 input1, T1 input2, T2 expected_result)
{
    vector<string> vec_input1;
    vector<string> vec_input2;

    stringstream ss;
    string tempStr;
    ss.str(input1);
    while (ss >> tempStr) {
        vec_input1.push_back(tempStr);
    }
    ss.str(input2);
    ss.seekg(0);
    while (ss >> tempStr) {
        vec_input2.push_back(tempStr);
    }
    cout << "parti size : " << vec_input1.size() << endl;
    cout << "comple size : " << vec_input2.size() << endl;

    //result
    string result = solution(vec_input1, vec_input2);
    if (result == expected_result) {
        cout << "Pass : " << result << endl;
        return true;
    }
    else {
        cout << "false result : " << result << endl;
        return false;
    }
}
