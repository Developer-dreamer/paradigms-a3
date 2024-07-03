#include <iostream>
#include <dlfcn.h>
#include <limits>
#include <algorithm>
#include "CaesarAlgorythm-s.h"
using namespace std;

char* read_console() {
    int inputTextLen_ = 64;

    cout << "Enter a string: ";

    char ch;
    auto inputText_ = new char[inputTextLen_ + 1]; // Extra space for '\0'
    int size = 0;

    while ((ch = cin.get()) != '\n') {
        if (size == inputTextLen_) {
            // Resize the array
            inputTextLen_ *= 2;
            const auto temp = new char[inputTextLen_ + 1]; // Extra space for '\0'
            std::copy_n(inputText_, size, temp);
            delete[] inputText_;
            inputText_ = temp;
        }
        inputText_[size++] = ch;
    }

    if (size == inputTextLen_) {
        inputTextLen_ *= 2;
        const auto temp = new char[inputTextLen_ + 1]; // Extra space for '\0'
        std::copy_n(inputText_, size, temp);
        delete[] inputText_;
        inputText_ = temp;
    }
    // Add the null terminator
    inputText_[size] = '\0';

    cout << "String " << inputText_ << endl; // Print inputText_
    cin.clear();
    return inputText_;
}

int read_key() {
    int key;
    while (true) {
        cout << "Enter a key: ";
        cin >> key;
        if (!cin.fail())
        {
            break;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a valid integer." << endl;
    }
    return key;
}


int main() {
    const char* text = read_console();
    const int key = read_key();

    const char* encryptedText = CaesarAlgorythmEncrypt(text, key);
    delete[] text; // Delete the old text
    cout << "Encrypted text: " << encryptedText << endl;

    const char* decryptedText = CaesarAlgorythmDecrypt(encryptedText, key);
    delete[] encryptedText; // Delete the encrypted text
    cout << "Decrypted text: " << decryptedText << endl;

    delete[] decryptedText;
}

