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
    int answer = 1;
    map<string, int> map_clothes;
    for (int i = 0; i < clothes.size(); i++) {
        map<string, int>::iterator iter = map_clothes.find(clothes[i][1]);
        if (map_clothes.end() == iter) {
            map_clothes.insert(make_pair(clothes[i][1], 1));
        }
        else {
            (*iter).second += 1;
        }
    }

    for (map<string, int>::iterator iter = map_clothes.begin(); iter != map_clothes.end(); iter++) {
        answer = answer * ((*iter).second + 1);
    }
    answer = answer - 1;
    return answer;
}

bool programmers_io(string input1, int expected_result)
{
    vector<vector<string>> clothes;
    stringstream ss;
    string tempStr;
    ss.str(input1);
    while (ss >> tempStr) {
        vector<string> vec_input1;
        vec_input1.push_back(tempStr);
        ss >> tempStr;
        vec_input1.push_back(tempStr);
        clothes.push_back(vec_input1);
    }

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
    string input1 = "yellow_hat headgear blue_sunglasses eyewear green_turban headgear";
    int expected_result = 5;
    bool result = programmers_io(input1, expected_result);
}
