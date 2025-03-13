#pragma once // ２重インクルードを防止する
#include <string> // std::stringをつかうため

class func
{
private:
    
public:
    func();
    ~func();
    void func1(std::string); // <string>にあるstd::stringを使う
};
