#include <iostream>

enum ForeColour {
    Default = 0,
    Black = 30,
    Red = 31,
    Green = 32,
    Yellow = 33,
    Blue = 34,
    Magenta = 35,
    Cyan = 36,
    White = 37,
};

int main() {
    std::cout << "화면에 그림을 그리는 프로그램입니다." << std::endl;
    std::cout << "학번: 202027044" << std::endl;
    std::cout << "이름: 장민혁" << std::endl << std::endl;

    int num = 0;

    while (num != 64 || num != 1000000) {
        std::cout << "화면에 그릴 물체코드를 입력하세요: ";
        std::cin >> num;

        if (num == 1) {
            std::cout << "\x1b[37m■\x1b[0m" << std::endl;
        }
        else if (num == 2 || num == 10) {
            std::cout << "\x1b[31m■\x1b[0m" << std::endl;
        }
        else if (num == 4 || num == 100) {
            std::cout << "\x1b[32m■\x1b[0m" << std::endl;
        }
        else if (num == 8 || num == 1000) {
            std::cout << "\x1b[33m■\x1b[0m" << std::endl;
        }
        else if (num == 16 || num == 10000) {
            std::cout << "\x1b[36m■\x1b[0m" << std::endl;
        }
        else if (num == 32 || num == 100000) {
            std::cout << "\x1b[35m■\x1b[0m" << std::endl;
        }
    }
}