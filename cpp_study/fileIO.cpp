#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char** argv)
{
    // 파일 리딩 준비
    std::ifstream txtfile;
    txtfile.open("C:/Users/tjsdn2560/Desktop/git/Algorithms_sunny/fileIO.txt");

    // 혹은 이런방법도 존재함
    // !!!!! 초기 시작할때는 무조건 open함수 없이해야됨
    // !!!!! 나중에 txtfile 재사용시에는 open함수 필수
    // !!!!!!!!!!!!!객체 생성자이므로 저런식으로 형성됨
    // std::ifstream txtfile("fileIO.txt");

    std::string s;

    if (txtfile.is_open()) {
        // white space  ->  it read seperate string
        // space, tab, enter  ->  white space
        // same work with std::cin
        txtfile >> s;
        std::cout << "s : " << s << std::endl;
    }
    else {
        throw std::invalid_argument("file open error\n");
    }

    // read new file
    // 1. close previous one
    // 2. open new one
    txtfile.close();
    txtfile.open("C:/Users/tjsdn2560/Desktop/git/Algorithms_sunny/fileIO2.txt");

    // result : 2077656e
    // little indian -> space w e n
    // ascii 20 -> space
    // read 4 character -> int(ascii)
    int temp_hex = 0;
    if (txtfile.is_open()) {
        txtfile.read((char*)(&temp_hex), 4);
        std::cout << std::hex << temp_hex << std::endl;
    }
    else {
        throw std::invalid_argument("file open error\n");
    }

    txtfile.close();
    // binary mode
    // default is string
    txtfile.open("C:/Users/tjsdn2560/Desktop/git/Algorithms_sunny/fileIO2.txt", std::ios::binary);
    char c[15];
    if (txtfile.is_open()) {
        txtfile.read(c, 15);
        // c[15] = NULL;
        // garbage data out
        // without null in last of array -> stream will return grabage value!!!
        std::cout << c << std::endl;
        // NULL, '\0', 0 any of them is ok
        c[15] = 0;
        std::cout << c << std::endl;
        // or just print each of array element
        for (int i = 0; i < 15; i++) {
            std::cout << std::hex << c[i];
        }
        std::cout << std::endl;
    }
    else {
        throw std::invalid_argument("file open error\n");
    }

    txtfile.close();
    // ate -> file pointer moves to eof
    txtfile.open("C:/Users/tjsdn2560/Desktop/git/Algorithms_sunny/fileIO3.txt", std::ifstream::ate | std::ifstream::binary);
    int size;
    if (txtfile.is_open()) {
        // get 'position' of 'file pointer'
        size = txtfile.tellg();
        std::cout << size << std::endl;
    }
    else {
        throw std::invalid_argument("file open error\n");
    }
}