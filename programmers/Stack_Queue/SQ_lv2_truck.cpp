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

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    int answer = 0;
    // truck x, x+1 > length. then only x passed and answer += length
    // <truck_weights, pos>
    // pos-> 0(waiting) -> 1 ~ bridge_length(on bridge) -> dequeue
    // caution!!!
    // vector for loop!!
    // if erase iterater pulled one position!!!
    // iter++; have to seperated with erase!!!
    vector<pair<int, int>> q;
    int bridge_weight = 0;
    int count = 0;
    //cout << truck_weights.size();
    while (true) {
        for (vector<pair<int, int>>::iterator iter = q.begin(); iter != q.end();) {
            (*iter).second += 1;
            if ((*iter).second == bridge_length + 1) {
                bridge_weight -= (*iter).first;
                q.erase(q.begin());
            }
            else {
                iter++;
            }
        }
        if (count == truck_weights.size() && q.size() == 0) {
            answer++;
            break;
        }
        if (bridge_weight + truck_weights[count] <= weight && count < truck_weights.size()) {
            q.push_back(make_pair(truck_weights[count], 1));
            bridge_weight += truck_weights[count];
            count++;
        }
        answer++;
    }
    return answer;
}

bool programmers_io(int input1, int input2, string s_input3, int expected_result)
{
    vector<int> vi_input3;

    stringstream ss;
    string tempStr;
    ss.str(s_input3);
    while (ss >> tempStr) {
        vi_input3.push_back(stoi(tempStr));
    }

    //result
    int result = solution(input1, input2, vi_input3);
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
    int i_input1 = 100;
    int i_input2 = 100;
    string s_input3 = "10 10 10 10 10 10 10 10 10 10";
    int i_expected_result = 110;

    bool result = programmers_io(i_input1, i_input2, s_input3, i_expected_result);
}
