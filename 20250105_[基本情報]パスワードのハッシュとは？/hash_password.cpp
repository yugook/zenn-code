#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <openssl/sha.h>

// パスワードをSHA-256でハッシュ化する関数
std::string hashPassword(const std::string &password)
{
    // SHA256の出力サイズは32バイト
    unsigned char hash[SHA256_DIGEST_LENGTH];

    // ハッシュ化
    SHA256(reinterpret_cast<const unsigned char *>(password.c_str()), password.size(), hash);

    // ハッシュ値を16進数文字列に変換
    std::ostringstream oss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i)
    {
        oss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(hash[i]);
    }

    return oss.str();
}

int main()
{
    // ユーザーからパスワードを入力
    std::string password;
    std::cout << "Enter password: ";
    std::cin >> password;

    // パスワードをハッシュ化
    std::string hashedPassword = hashPassword(password);
    std::cout << "Hashed password (SHA-256): " << hashedPassword << std::endl;

    // パスワードをメモリクリア
    std::fill(password.begin(), password.end(), '\0');
    std::cout << "Password clear: " << password << std::endl;

    // パスワード認証を入力
    std::string tryPassword;
    std::cout << "Enter tryPassword: ";
    std::cin >> tryPassword;

    // パスワード認証をハッシュ化
    std::string tryHashedPassword = hashPassword(tryPassword);
    std::cout << "tryHashedPassword (SHA-256): " << tryHashedPassword << std::endl;

    // パスワード認証をメモリクリア
    std::fill(tryPassword.begin(), tryPassword.end(), '\0');
    std::cout << "Password clear: " << tryPassword << std::endl;

    // パスワード認証
    if (hashedPassword == tryHashedPassword)
        std::cout << "Successful" << std::endl;
    else
        std::cout << "Failed" << std::endl;

    return 0;
}