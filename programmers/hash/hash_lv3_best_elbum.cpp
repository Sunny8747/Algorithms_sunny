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

bool comp_pair_desc(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first) {
        return a.second < b.second;
    }
    else {
        return a.first > b.first;
    }
}

bool comp_si_pair_desc(pair<string, int> a, pair<string, int> b)
{
    return a.second > b.second;
}
vector<int> solution(vector<string> genres, vector<int> plays)
{
    vector<int> answer;
    map<string, vector<pair<int, int>>> map_music;
    map<string, int> map_sum;
    for (int i = 0; i < genres.size(); i++) {
        map<string, vector<pair<int, int>>>::iterator iter_map_music = map_music.find(genres[i]);
        if (iter_map_music == map_music.end()) {
            vector<pair<int, int>> temp_vec(1, make_pair(plays[i], i));
            map_music.insert(make_pair(genres[i], temp_vec));
        }
        else {
            (*iter_map_music).second.push_back(make_pair(plays[i], i));
        }

        map<string, int>::iterator iter_sum = map_sum.find(genres[i]);
        if (iter_sum == map_sum.end()) {
            map_sum.insert(make_pair(genres[i], plays[i]));
        }
        else {
            (*iter_sum).second = (*iter_sum).second + plays[i];
        }
    }
    for (auto iter = map_music.begin(); iter != map_music.end(); iter++) {
        sort((*iter).second.begin(), (*iter).second.end(), comp_pair_desc);
    }
    vector<pair<string, int>> vec_sum;
    for (auto iter = map_sum.begin(); iter != map_sum.end(); iter++) {
        vec_sum.push_back(make_pair((*iter).first, (*iter).second));
    }
    sort(vec_sum.begin(), vec_sum.end(), comp_si_pair_desc);
    //map_sum value 값으로 정렬필요함 백터로 넣어서 할지 아니면 처음부터 맵말고 백터로만들지 고민중

    for (auto iter_sum = vec_sum.begin(); iter_sum != vec_sum.end(); iter_sum++) {
        int count = 0;
        map<string, vector<pair<int, int>>>::iterator iter_map_music = map_music.find((*iter_sum).first);
        for (int j = 0; j < (*iter_map_music).second.size(); j++) {
            count++;
            answer.push_back((*iter_map_music).second[j].second);
            cout << (*iter_map_music).second[j].first << " ";
            if (count == 2) {
                break;
            }
        }
    }
    return answer;
}

bool programmers_io(string* input1, int size_input1, string input2, vector<int> expected_result)
{
    vector<string> vec_input1;
    vector<int> vec_input2;
    for (int i = 0; i < size_input1; i++) {
        vec_input1.push_back(input1[i]);
    }

    stringstream ss;
    string tempStr;
    ss.str(input2);
    while (ss >> tempStr) {
        vec_input2.push_back(stoi(tempStr));
    }

    //result
    vector<int> result = solution(vec_input1, vec_input2);
    if (result == expected_result) {
        cout << "Pass : ";
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << " ";
        }
        cout << endl;
        return true;
    }
    else {
        cout << "false result : ";
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
    string input1[] = {"classic", "pop", "classic", "classic", "pop"};
    string input2 = {"500 600 150 800 2500"};
    vector<int> expected_result;
    expected_result.push_back(4);
    expected_result.push_back(1);
    expected_result.push_back(3);
    expected_result.push_back(0);

    bool result = programmers_io(input1, N_ELEMENTS(input1), input2, expected_result);
    return result;
}
