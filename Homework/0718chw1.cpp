#include <iostream>

void main()
{
    //n은 가장 긴 줄의 별 갯수의 절반

    //for (int i = 1, n = 5, result; i < 2 * n; result = ((n - i) + ((n - i) >> 31)) ^ ((n - i) >> 31), std::cout << std::string(result, ' ') << std::string(2 * (n - result), '*') << '\n', i++);
    
    for (int i = 0, n = 6; i < (n * 2) * ((n * 2) - 1) -1; std::cout << " *"[((-2 * ((i % (n * 2)) / n) + 1) * ((i % (n * 2)) % n) + ((i % (n * 2)) / n) * (n - 1) + (-2 * ((i / (n * 2)) / n) + 1) * ((i / (n * 2)) % n) + ((i / (n * 2)) / n) * (n - 2) + 1) / n] << "\n\0\0\0\0\0\0\0\0\0\0\0"[(i % (n * 2) + (n * 2) + 1) % (n * 2)], i++);

}

//int n = 5;
//
//for (int i = 0; i < (n * 2) * ((n * 2) - 1) -1; i++)
//{
//    int x = i % (n * 2); //x 좌표
//    int y = i / (n * 2); //y 좌표
//
//    int xWeight = -2 * (x / n) + 1; // -1 | 1
//    int yWeight = -2 * (y / n) + 1; // -1 | 1
//    int xBias = (x / n) * (n - 1); // 0 | n
//    int yBias = (y / n) * (n - 2); // 0 | n
//
//    int ax = xWeight * (x % n) + xBias;
//    int ay = yWeight * (y % n) + yBias;
//
//    std::cout << " *"[(ax + ay + 1) / n];
//    std::cout << "\n\0\0\0\0\0\0\0\0\0\0\0\0\0\0"[(x + (n * 2) + 1) % (n * 2)]; // 한줄이 끝나면 개행문자 출력 외에는 null문자로 무시
//}

//BOM -> 엔디안
//제곱근을 구현하고 그걸로 문자열을 구성하고 나머지로 나눠서 길이를 늘리는 방식 -> 바빌로니아법(헤론법)? -> 반복해야하는데..?