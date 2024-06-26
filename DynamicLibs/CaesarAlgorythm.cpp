#include <iostream>

extern "C"
{
    __attribute__((visibility("default"))) char* CaesarAlgorythmEncrypt(char* text, int key)
    {
        for (int i = 0; text[i] != '\0'; i++)
        {
            if (text[i] >= 'a' && text[i] <= 'z')
            {
                text[i] = static_cast<char>((text[i] - 'a' + key) % 26 + 'a');
            }
            else if (text[i] >= 'A' && text[i] <= 'Z')
            {
                text[i] = static_cast<char>((text[i] - 'A' + key) % 26 + 'A');
            }
        }

        return text;
    }

    __attribute__((visibility("default"))) char* CaesarAlgorythmDecrypt(char* text, int key)
    {
        for (int i = 0; text[i] != '\0'; i++)
        {
            if (text[i] >= 'a' && text[i] <= 'z')
            {
                text[i] = static_cast<char>((text[i] - 'a' - key + 26) % 26 + 'a');
            }
            else if (text[i] >= 'A' && text[i] <= 'Z')
            {
                text[i] = static_cast<char>((text[i] - 'A' - key + 26) % 26 + 'A');
            }
        }

        return text;
    }

}