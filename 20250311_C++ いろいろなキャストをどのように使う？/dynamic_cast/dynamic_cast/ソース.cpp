// ダウンキャスト 「基底クラス → 派生クラス」への変換。危険！dynamic_cast などが必要。
#include <iostream>
#include <typeinfo>

// 基底クラス（親クラス）
class Base
{
public:
    virtual void foo() {} // 仮想関数を持たせることで、RTTI（実行時型情報）が有効になる
};

// 派生クラス（子クラス）
class Derived : public Base
{
public:
    void bar() { std::cout << "Derived::bar() が呼び出されました！" << std::endl; }
};

int main()
{
    // Derived クラスのインスタンスを作成し、Base クラスのポインタで受け取る
    Base* base = new Derived(); // アップキャスト（派生クラス → 基底クラス）
    //Base* base = new Base(); // Derived ではなく Base のインスタンス → 失敗するパターン

    // ダウンキャスト（基底クラス → 派生クラス）
    // dynamic_cast を使うことで、実行時に安全性をチェックしつつキャストする
    Derived* derived = dynamic_cast<Derived*>(base);

    if (derived != nullptr) // キャストができているかチェック
    {
        std::cout << "ダウンキャスト成功！" << std::endl;

        // 派生クラスのメソッドを呼び出す
        derived->bar();

        // 実体が何の型かを typeid で確認する
        std::cout << "base が指している実体の型: " << typeid(*base).name() << std::endl;
        std::cout << "derived が指している実体の型: " << typeid(*derived).name() << std::endl;
    }
    else {
        std::cout << "ダウンキャスト失敗" << std::endl;
    }

    delete base; // メモリ解放
    return 0;
}




// アップキャスト 「派生クラス → 基底クラス」への変換。安全！通常は 暗黙的 にできる。
//#include <iostream>
//#include <typeinfo>
//
//class Base {
//    virtual void foo() {} // 仮想関数
//};
//
//class Derived : public Base {
//
//};
//
//int main() {
//    Derived* derived = new Derived(); // 派生クラスのインスタンス
//    Base* base = derived;             // アップキャスト（これは暗黙でOK）
//
//    // ↓型情報を表示（動的型は実体の型を表す）
//    std::cout << "derived の動的型: " << typeid(*derived).name() << std::endl; // Derived
//    std::cout << "base の動的型: " << typeid(*base).name() << std::endl;       // Derived
//
//    delete derived;
//    return 0;
//}
