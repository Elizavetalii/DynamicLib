#include <iostream>
#include "..\DynamicLib\Header.h"
#include "Windows.h"
#include <string>

typedef bool (*CheckCharactersFunc)(const char*, const char*);

int main() {
    SetConsoleCP(1251); // Устанавливаем кодировку консоли для поддержки кириллицы
    setlocale(LC_ALL, "Russian");

    std::string inputString;
    std::string charactersToFind;
    HMODULE load;
    CheckCharactersFunc checkCharacters;

    // Запрос у пользователя строки и символов для поиска
    std::cout << "Введите текст: ";
    std::getline(std::cin, inputString);
    std::cout << "Введите символы для поиска: ";
    std::getline(std::cin, charactersToFind);

    // Загрузка DLL
    load = LoadLibrary(L"DynamicLib.dll");
    if (load == NULL) {
        std::cerr << "Не получилось загрузить DLL." << std::endl;
        return 1;
    }

    // Получение адреса функции
    checkCharacters = (CheckCharactersFunc)GetProcAddress(load, "CheckCharacters");
    if (checkCharacters == NULL) {
        std::cerr << "Не удалось найти функцию." << std::endl;
        FreeLibrary(load);
        return 0;
    }

    // Вызов функции
    bool result = checkCharacters(inputString.c_str(), charactersToFind.c_str());

    // Вывод результата
    std::cout << "Результат: " << (result ? "true" : "false") << std::endl;

    // Освобождение библиотеки
    FreeLibrary(load);

    return 0;
}
