map의 경우

map<string,int> m;
m["key"] = "value" 로 init 가능
만약 "key"가 존재했으면 "value" change

find(m.begin(), m.end(), some_string) 했더니 iter값이 안나왔음 -> 오류나옴
some_map.find("key") 로해야됨 못찾으면 some_map.end()

some_map.count("key")로 찾을수도 있음 그렇게되면 찾으면 1 못찾으면 0리턴
if(some_map.count("key")){}
도 가능
