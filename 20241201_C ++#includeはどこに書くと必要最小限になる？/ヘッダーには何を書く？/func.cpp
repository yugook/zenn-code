#include "func.hpp" // クラス宣言をインクルードする
// #include <string> // std::stringをつかうため

// class func
// {
// private:
    
// public:
//     func();
//     ~func();
//     void func1(std::string); // <string>にあるstd::stringを使う
// };
#include <iostream> // std::cout, std::endlを使うため

func::func()
{
}

func::~func()
{
}

void func::func1(std::string s)
{
    std::cout << s << std::endl; // <iostream>のstd::cout, std::endlを使う
}

