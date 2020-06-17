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
#include <map>
using namespace std;

#define N_ELEMENTS(array) (sizeof(array) / sizeof((array)[0]))

bool solution(vector<string> phone_book)
{
    bool answer = true;
    sort(phone_book.begin(), phone_book.end());
    for (int i = 0; i < phone_book.size(); i++) {
        //last elem
        if (i == phone_book.size() - 1) {
        }
        else {
            if (phone_book[i].length() <= phone_book[i + 1].size()) {
                string temp = phone_book[i + 1].substr(0, phone_book[i].length());
                if (temp == phone_book[i]) {
                    return false;
                }
            }
        }
    }
    return answer;
}

bool programmers_io(string* input1, int size_input, bool expected_result)
{
    vector<string> vec_input1;
    for (int i = 0; i < size_input; i++) {
        vec_input1.push_back(input1[i]);
    }

    //result
    bool result = solution(vec_input1);
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
    string input1[] = {"119", "97674223", "1195524421"};
    bool expected_result = false;

    bool result = programmers_io(input1, N_ELEMENTS(input1), expected_result);
}
