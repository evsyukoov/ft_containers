//
// Created by 1 on 26.11.2020.
//

#include <vector>
#include <stack>
#include <queue>
#include <list>
#include "stack.hpp"
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define RESET "\033[0m"


template<typename T>
void    test1(T &myqueue)
{
    myqueue.push(77);
    myqueue.push(1);
    myqueue.push(16);

    myqueue.front() -= myqueue.back();    // 77-16=61

    std::cout << "myqueue.front() is now " << myqueue.front() << std::endl;
}

template<typename T>
void    test2(T &myqueue)
{
    myqueue.push(50);
    myqueue.push(51);
    myqueue.push(52);
    while (!myqueue.empty())
    {
        std::cout << ' ' << myqueue.front();
        myqueue.pop();
    }
    std::cout << '\n';
}

int     main()
{
    std::queue<int> lib;
    std::queue<int> my;
    std::cout << GREEN <<  "          Lib test back & front " << RESET << std::endl;
    test1(lib);
    std::cout <<  "          my test back & front" << std::endl;
    test1(my);
    std::cout <<  "          Lib test push && pop " << std::endl;
    test2(lib);
    std::cout <<  "          my test push && pop" << std::endl;
    test2(my);
    std::cout <<  "          Lib test size " << std::endl;
    std::cout << lib.size() << std::endl;
    std::cout <<  "          my test size" << std::endl;
    std::cout << my.size() << std::endl;
}

