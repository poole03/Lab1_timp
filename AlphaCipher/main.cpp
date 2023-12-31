#include <iostream>
#include <cctype>
#include "modAlphaCipher.h"
#include <locale>
using namespace std;

bool isValid(const wstring& s)
{
    for(auto c : s)
        if (!iswalpha(c) || !iswupper(c))
            return false;
    return true;
}

int main(int argc, char **argv)
{
    setlocale(LC_ALL, "ru_RU.UTF-8");
    wstring key;
    wstring text;
    unsigned op;
    wcout << L"Cipher ready. Input key: ";
    getline(wcin, key); // Считываем строку вместо wcin
    if (!isValid(key)) {
        wcerr << L"Key not valid\n";
        return 1;
    }
    wcout << L"Key loaded\n";
    modAlphaCipher cipher(key);
    do {
        wcout << L"Cipher ready. Input operation (0-exit, 1-encrypt, 2-decrypt): ";
        wcin >> op;
        if (op > 2) {
            wcout << L"Illegal operation\n";
        } else if (op > 0) {
            wcin.ignore(); // Сбрасываем символ новой строки в буфере
            wcout << L"Cipher ready. Input text: ";
            getline(wcin, text); // Считываем строку вместо wcin
            if (isValid(text)) {
                if (op == 1) {
                    wcout << L"Encrypted text: " << cipher.encrypt(text) << endl;
                } else {
                    wcout << L"Decrypted text: " << cipher.decrypt(text) << endl;
                }
            } else {
                wcout << L"Operation aborted: invalid text\n";
            }
        }
    } while (op != 0);
    return 0;
}
