// for making test env
#include <iostream>
#include <sstream>
// real input
#include <algorithm>
#include <map>
#include <string>
#include <vector>

using namespace std;

string solution(vector<string> participant, vector<string> completion)
{
    // ver 1 -> only vector
    // vector<string>::iterator iter;
    // for (int i = 0; i < completion.size(); i++) {
    //     iter = find(participant.begin(), participant.end(), completion.at(i));
    //     participant.erase(iter);
    // }
    // if out_of_range comes then participant size and finding position doesn't match
    // if position is 0 then it has no elem
    // return participant.at(0);

    //ver 2 -> more fast if large input
    //mapping
    map<string, int> m_parti;
    map<string, int>::iterator iter;
    for (int i = 0; i < participant.size(); i++) {
        if (!m_parti.insert(pair<string, int>(participant.at(i), 0)).second) {
            m_parti.find(participant.at(i))->second += 1;
        }
    }
    //
    int temp_num = 0;
    for (int i = 0; i < completion.size(); i++) {
        m_parti.find(completion.at(i))->second -= 1;
    }
    for (iter = m_parti.begin(); iter != m_parti.end(); iter++) {
        if (iter->second == 0) {
            return iter->first;
        }
    }

    // ver3 -> sorting (Not my Code!!!)
    // Sorting
    // sort(participant.begin(), participant.end());
    // sort(completion.begin(), completion.end());
    // for(int i=0;i<completion.size();i++)
    // {
    //     if(participant[i] != completion[i])
    //         return participant[i];
    // }
    // return participant[participant.size() - 1];

    cout << "parti size : " << participant.size() << endl;
    cout << "comple size : " << completion.size() << endl;

    return "false";
}

int main(int argc, char** argv)
{
    // making test set
    vector<string> participant;
    vector<string> completion;

    stringstream ss;
    string tempStr;
    ss.str("marina josipa nikola vinko filipa");
    while (!ss.eof()) {
        ss >> tempStr;
        cout << "tempStr : " << tempStr << endl;
        participant.push_back(tempStr);
    }
    ss.str("josipa filipa marina nikola");

    // important!!!!!!!!!!!!
    // without seekg -> set file pointer to front
    // the file pointer of string stream doesn't set to initial state;
    ss.seekg(0);
    // important!!!!!!!!!!!!

    // eof and >> both works
    while (ss >> tempStr) {
        completion.push_back(tempStr);
    }
    cout << "parti size : " << participant.size() << endl;
    cout << "comple size : " << completion.size() << endl;

    // get result
    string result = solution(participant, completion);
    if (result == "vinko") {
        cout << "Ok" << endl;
    }
    else {
        cout << "false result : " << result << endl;
    }
}
