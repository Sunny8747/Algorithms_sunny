#include <iostream>
#include <vector>

using namespace std;

void teset() { printf("teset\n"); }

template <typename T>
class Node {
public:
    Node(T t) : elem(t) {}
    ~Node()
    {
        cout << "Node delete : " << elem << endl;
    }

private:
    T elem;
};

int main(int argc, char** argv)
{
    vector<int> vec_int;
    printf("test\n");
    int test = 1;
    for (int i = 0; i < 10; i++) {
        test++;
    }

    teset();

    cout << test << endl;
    cout << argc << endl;
    cout << argv[0] << endl;
    cout << argv[1] << endl;
    cout << argv[2] << endl;
}