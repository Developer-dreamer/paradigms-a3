#include <cstring>
#include <iostream>
#include "CaesarAlgorythm-s.h"

char* CaesarAlgorythmEncrypt(const char* text, const int key)
{
    // -------Used for debugging-------
    // printf("Encrypting text: %s\n Key: %d\n", text, key);
    // --------------------------------

    char* encryptedText = new char[strlen(text) + 1];
    strcpy(encryptedText, text);

    for (int i = 0; encryptedText[i] != '\0'; i++)
    {
        if (encryptedText[i] >= 'a' && encryptedText[i] <= 'z')
        {
            encryptedText[i] = static_cast<char>((encryptedText[i] - 'a' + key) % 26 + 'a');
        }
        else if (encryptedText[i] >= 'A' && encryptedText[i] <= 'Z')
        {
            encryptedText[i] = static_cast<char>((encryptedText[i] - 'A' + key) % 26 + 'A');
        }
    }

    return encryptedText;
}
char* CaesarAlgorythmDecrypt(const char* text, const int key)
{
    // -------Used for debugging-------
    // printf("Derypting text: %s\n Key: %d\n", text, key);
    // --------------------------------

    char* decryptedText = new char[strlen(text) + 1];
    strcpy(decryptedText, text);

    for (int i = 0; decryptedText[i] != '\0'; i++)
    {
        if (decryptedText[i] >= 'a' && decryptedText[i] <= 'z')
        {
            decryptedText[i] = static_cast<char>((decryptedText[i] - 'a' - key + 26) % 26 + 'a');
        }
        else if (decryptedText[i] >= 'A' && decryptedText[i] <= 'Z')
        {
            decryptedText[i] = static_cast<char>((decryptedText[i] - 'A' - key + 26) % 26 + 'A');
        }
    }

    return decryptedText;
}
