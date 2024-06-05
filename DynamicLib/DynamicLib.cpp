#include <vcruntime_string.h>
__declspec(dllexport) bool CheckCharacters(const char* inputString, const char* charactersToFind)
{
    // Проверка, что обе строки не пусты
    if (inputString == nullptr || charactersToFind == nullptr) return false;

    // Поиск каждого символа из charactersToFind в inputString
    for (const char* p = charactersToFind; *p != '\0'; ++p) {
        if (strchr(inputString, *p) == nullptr) {
            // Если символ не найден, возвращаем false
            return false;
        }
    }
    // Все символы найдены, возвращаем true
    return true;
}