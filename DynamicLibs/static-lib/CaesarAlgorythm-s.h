//
// Created by serafym on 7/3/24.
//

#ifndef CAESARALGORYTHM_S_H
#define CAESARALGORYTHM_S_H

extern "C"{
    char* CaesarAlgorythmEncrypt(const char* text, const int key);
    char* CaesarAlgorythmDecrypt(const char* text, const int key);
}

#endif //CAESARALGORYTHM_S_H
