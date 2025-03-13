// �_�E���L���X�g �u���N���X �� �h���N���X�v�ւ̕ϊ��B�댯�Idynamic_cast �Ȃǂ��K�v�B
#include <iostream>
#include <typeinfo>

// ���N���X�i�e�N���X�j
class Base
{
public:
    virtual void foo() {} // ���z�֐����������邱�ƂŁARTTI�i���s���^���j���L���ɂȂ�
};

// �h���N���X�i�q�N���X�j
class Derived : public Base
{
public:
    void bar() { std::cout << "Derived::bar() ���Ăяo����܂����I" << std::endl; }
};

int main()
{
    // Derived �N���X�̃C���X�^���X���쐬���ABase �N���X�̃|�C���^�Ŏ󂯎��
    Base* base = new Derived(); // �A�b�v�L���X�g�i�h���N���X �� ���N���X�j
    //Base* base = new Base(); // Derived �ł͂Ȃ� Base �̃C���X�^���X �� ���s����p�^�[��

    // �_�E���L���X�g�i���N���X �� �h���N���X�j
    // dynamic_cast ���g�����ƂŁA���s���Ɉ��S�����`�F�b�N���L���X�g����
    Derived* derived = dynamic_cast<Derived*>(base);

    if (derived != nullptr) // �L���X�g���ł��Ă��邩�`�F�b�N
    {
        std::cout << "�_�E���L���X�g�����I" << std::endl;

        // �h���N���X�̃��\�b�h���Ăяo��
        derived->bar();

        // ���̂����̌^���� typeid �Ŋm�F����
        std::cout << "base ���w���Ă�����̂̌^: " << typeid(*base).name() << std::endl;
        std::cout << "derived ���w���Ă�����̂̌^: " << typeid(*derived).name() << std::endl;
    }
    else {
        std::cout << "�_�E���L���X�g���s" << std::endl;
    }

    delete base; // ���������
    return 0;
}




// �A�b�v�L���X�g �u�h���N���X �� ���N���X�v�ւ̕ϊ��B���S�I�ʏ�� �ÖٓI �ɂł���B
//#include <iostream>
//#include <typeinfo>
//
//class Base {
//    virtual void foo() {} // ���z�֐�
//};
//
//class Derived : public Base {
//
//};
//
//int main() {
//    Derived* derived = new Derived(); // �h���N���X�̃C���X�^���X
//    Base* base = derived;             // �A�b�v�L���X�g�i����͈Öق�OK�j
//
//    // ���^����\���i���I�^�͎��̂̌^��\���j
//    std::cout << "derived �̓��I�^: " << typeid(*derived).name() << std::endl; // Derived
//    std::cout << "base �̓��I�^: " << typeid(*base).name() << std::endl;       // Derived
//
//    delete derived;
//    return 0;
//}
