map의 경우

map<string,int> m;
m[some_string] 으로 찾을수있음
이럴경우 못찾으면 0
찾으면 value가 나오는듯함

find(m.begin(), m.end(), some_string) 했더니 iter값이 안나왔음
아마 value값이 나오는듯?
