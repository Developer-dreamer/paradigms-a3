#include <iostream>
#include <dlfcn.h>

int main()
{
    typedef char*(*CaesarAlgorythmEncrypt)(char*, int);
    typedef char*(*CaesarAlgorythmDecrypt)(char*, int);

    void* handle = dlopen("./libCaesarAlgorythm.so", RTLD_LAZY);
    if (!handle) {
        std::cerr << "Cannot open library: " << dlerror() << '\n';
        return -1;
    }

    // reset errors
    dlerror();

    auto encryptFunc = static_cast<CaesarAlgorythmEncrypt>(dlsym(handle, "CaesarAlgorythmEncrypt"));
    const char *dlsym_error = dlerror();
    if (dlsym_error) {
        std::cerr << "Cannot load symbol 'CaesarAlgorythmEncrypt': " << dlsym_error << '\n';
        dlclose(handle);
        return -1;
    }

    auto decryptFunc = static_cast<CaesarAlgorythmDecrypt>(dlsym(handle, "CaesarAlgorythmDecrypt"));
    dlsym_error = dlerror();
    if (dlsym_error) {
        std::cerr << "Cannot load symbol 'CaesarAlgorythmDecrypt': " << dlsym_error << '\n';
        dlclose(handle);
        return -1;
    }

    // Use the function pointers `encryptFunc` and `decryptFunc` here...

    dlclose(handle);
}